#pragma once

enum dataType {
	EIGHT_BIT,
	SIXTEEN_BIT,
	THIRTY_TWO_BIT
};

static inline unsigned int getBytesCount(enum dataType dataType) {
	switch (dataType) {
		case EIGHT_BIT:
			return 1;

		case SIXTEEN_BIT:
			return 2;

		case THIRTY_TWO_BIT:
			return 4;
	}

	return 0;
}

static inline void writeInternal(unsigned int *address, unsigned int value, enum dataType dataType) {
	switch (dataType) {
		case EIGHT_BIT:
			*(unsigned char *) address = (unsigned char) value;
			break;

		case SIXTEEN_BIT:
			*(unsigned short *) address = (unsigned short) value;
			break;

		case THIRTY_TWO_BIT:
			*address = value;
			break;
	}
}

static inline unsigned int readInternal(const unsigned int *address, enum dataType dataType) {
	switch (dataType) {
		case EIGHT_BIT:
			return *(unsigned char *) address;

		case SIXTEEN_BIT:
			return *(unsigned short *) address;

		case THIRTY_TWO_BIT:
			return *address;

		default:
			return 0;
	}
}