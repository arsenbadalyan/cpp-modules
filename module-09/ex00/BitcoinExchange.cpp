#include "BitcoinExchange.hpp"

const std::string BitcoinExchange::DB_NAME = "data.csv";
const std::string BitcoinExchange::DB_DATE_COL_NAME = "date";
const std::string BitcoinExchange::DB_EXCHANGE_COL_NAME = "exchange_rate";
const int BitcoinExchange::MONTH_MAX_DAY[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
db_map BitcoinExchange::DB_COURSES_MAP;
const std::string BitcoinExchange::INPUT_FIRST_COL_NAME = "date";
const std::string BitcoinExchange::INPUT_SECOND_COL_NAME = "value";

BitcoinExchange::BitcoinExchange( void ) {}
BitcoinExchange::BitcoinExchange( const BitcoinExchange & ) {}
BitcoinExchange::~BitcoinExchange() {}
void BitcoinExchange::operator=( const BitcoinExchange & ) {}

void BitcoinExchange::validateDB( void ) {
	std::ifstream DB;

	DB.open(BitcoinExchange::DB_NAME);

	if (!DB)
		throw std::runtime_error(ERR_UNAVAILABLE_DB);

	std::string fileContent;
	std::string btcCourseKey, btcCourseValue;
	size_t commaPos;
	bool isEmpty = true;

	DB >> fileContent;
	commaPos = fileContent.find(',');
	if (commaPos == std::string::npos
		|| fileContent.substr(0, commaPos) != BitcoinExchange::DB_DATE_COL_NAME
		|| fileContent.substr(commaPos + 1, fileContent.length()) != BitcoinExchange::DB_EXCHANGE_COL_NAME)
			throw std::runtime_error(ERR_INVALID_DB);

	while(DB.good()) {
		if (isEmpty)
			isEmpty = false;
		DB >> fileContent;

		commaPos = fileContent.find(',');

		if (commaPos == std::string::npos)
			throw std::runtime_error(ERR_INVALID_DB);

		btcCourseKey = fileContent.substr(0, commaPos);
		btcCourseValue = fileContent.substr(commaPos + 1, fileContent.length());
		if (BitcoinExchange::isValidDate(btcCourseKey)
			&& BitcoinExchange::isValidAndInBoundsNumber(btcCourseValue, true))
				BitcoinExchange::DB_COURSES_MAP[btcCourseKey] = std::strtod(btcCourseValue.c_str(), NULL);
		else {
			BitcoinExchange::DB_COURSES_MAP.clear();
			throw std::runtime_error(ERR_INVALID_DB);
		}
	}

	if (isEmpty || BitcoinExchange::DB_COURSES_MAP.begin() == BitcoinExchange::DB_COURSES_MAP.end())
		throw std::runtime_error(ERR_EMPTY_DB);
}

void BitcoinExchange::executeInput( char * inputFile ) {
	const std::string fileName(inputFile);
	std::ifstream fileReader(fileName);

	if (!fileReader)
		throw std::runtime_error(ERR_INVALID_INPUT_FILE);

	std::string fileContent, date, course;
	std::string* inputLine;
	size_t splitSize;
	char delimiter = '|';

	std::getline(fileReader, fileContent);
	inputLine = BitcoinExchange::split(fileContent, delimiter, splitSize);

	if (splitSize == 2
		&& BitcoinExchange::trimWhitespaces(inputLine[0]) == std::string(BitcoinExchange::INPUT_FIRST_COL_NAME)
		&& BitcoinExchange::trimWhitespaces(inputLine[1]) == std::string(BitcoinExchange::INPUT_SECOND_COL_NAME))
			std::getline(fileReader, fileContent);

	while (fileReader) {

		if (!BitcoinExchange::trimWhitespaces(fileContent).length()) {
			std::getline(fileReader, fileContent);
			continue ;
		}
	
		inputLine = BitcoinExchange::split(fileContent, delimiter, splitSize);

		try {
			if (splitSize != 2)
				throw std::runtime_error(ERR_BAD_INPUT + fileContent);

			date = BitcoinExchange::trimWhitespaces(inputLine[0]);
			course = BitcoinExchange::trimWhitespaces(inputLine[1]);

			if (!BitcoinExchange::isValidDate(date)
				|| !BitcoinExchange::isValidAndInBoundsNumber(course, false))
				throw std::runtime_error(ERR_BAD_INPUT + fileContent);

			BitcoinExchange::calculateCourse(date, course);
		} catch (const std::exception & exc) {
			std::cout << "Error: " << exc.what() << std::endl;
		}

		std::getline(fileReader, fileContent);
	}
}

void BitcoinExchange::calculateCourse( const std::string & date, const std::string & course ) {
	db_map::iterator target;
	db_map::iterator db_start = BitcoinExchange::DB_COURSES_MAP.begin();
	db_map::iterator near_bound = BitcoinExchange::DB_COURSES_MAP.upper_bound(date);

	target = near_bound;
	if (near_bound != db_start)
		target = --near_bound;
	
	const double result = std::strtod(course.c_str(), NULL) * target->second;

	std::cout << date << " => " << course << " = " << result << std::endl;
}

bool BitcoinExchange::isValidDate( const std::string & date ) {
	std::string * datePart;
	size_t splittedSize, i = 0;
	int month;
	int year;

	datePart = BitcoinExchange::split(date, '-', splittedSize);

	if (splittedSize != 3)
		return (false);

	// DATE YEAR VALIDATION
	if (!datePart[i].length() || datePart[i].length() > 4
		|| !BitcoinExchange::isOnlyDigit(datePart[i], false)) {
		return (false);
	}
	year = std::atoi(datePart[i].c_str());

	i++;

	// DATE MONTH VALIDATION
	if (datePart[i].length() && datePart[i].length() <= 2
		&& BitcoinExchange::isOnlyDigit(datePart[i], false)) {
			month = std::atoi(datePart[i].c_str());

			if (month < 1 || month > 12)
				return (false);
		} else return (false);

	i++;

	// DATE DAY VALIDATION
	if (datePart[i].length() && datePart[i].length() <= 2
		&& BitcoinExchange::isOnlyDigit(datePart[i], false)) {
			int day = std::atoi(datePart[i].c_str());
			int dayLimit = BitcoinExchange::MONTH_MAX_DAY[month - 1];
			if (month == 2 && BitcoinExchange::isLeapYear(year))
				dayLimit++;

			if (day > dayLimit)
				return (false);

		} else return (false);

	return (true);
}

std::string* BitcoinExchange::split(const std::string& str, char delimiter, size_t & size) {
	size = 0;

	std::string token;
	std::stringstream ss(str);

	while (std::getline(ss, token, delimiter)) {
		if(!token.empty())
			size++;
	}

	std::string *dividedList = new std::string[size];
	size_t fillSize = 0;

	ss.clear();
	ss.seekg(0);

	while (std::getline(ss, token, delimiter)) {
		if(!token.empty()) {
			dividedList[fillSize] = token;
			fillSize++;
		}
	}

	return (dividedList);
}

std::string BitcoinExchange::trimWhitespaces( std::string & str ) {
	std::string::iterator start = str.begin();
	std::string::iterator end = str.end();

	while (start != end && std::isspace(*start))
		start++;

	if (start == end)
		return (std::string());

	end--;

	while (std::isspace(*end))
		end--;

	return std::string(start, end + 1);
}

bool BitcoinExchange::isOnlyDigit( const std::string & str, bool checkDot ) {
	size_t idx = 0;
	bool hasAlreadyDot = false;

	if (str[idx] && (str[idx] == '+' || str[idx] == '-') && str[idx + 1])
		idx++;

	while (str[idx]) {
		if (!std::isdigit(str[idx])) {
			if (checkDot && !hasAlreadyDot
				&& str[idx] == '.' && idx != 0
				&& idx != str.length() - 1) {
				hasAlreadyDot = true;
				idx++;
				continue ;
			}
			return (false);
		}
		idx++;
	}

	return (true);
}

bool BitcoinExchange::isLeapYear( int year ) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidAndInBoundsNumber( const std::string & source, bool isDBCol ) {
	if (BitcoinExchange::isOnlyDigit(source, true)) {
		double num = std::strtod(source.c_str(), NULL);

		if (isDBCol && num >= 0) 
			return (true);

		if (!isDBCol) {
			if (num >= BitcoinExchange::MIN_BOUND && num <= BitcoinExchange::MAX_BOUND)
				return (true);
			else if (num < BitcoinExchange::MIN_BOUND)
				throw std::runtime_error(ERR_NEG_NUM);
			else if (num > BitcoinExchange::MAX_BOUND)
				throw std::runtime_error(ERR_LARGE_NUM);
		}
	}

	return (false);
}