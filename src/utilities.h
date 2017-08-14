#pragma once

inline unsigned long getStringLength(const char *string) {
	const char *character;

	for (character = string; *character; ++character);
	return (character - string);
}