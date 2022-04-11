/*
 * encode_decode.cpp
 *
 *  Created on: Apr 7, 2022
 *      Author: ganzo
 */
#include <algorithm> // std::sort
#include <iomanip>
#include <iostream> // std::cout
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
Position: SDE1

An input string that only contains all lower case letters is given as shown
below. Each character in the input string is stored in a byte. Task is to encode
the string in a way it uses minimum space. (all lower case letters, so each
letter could be stored in 5 bits instead of 8 bits).

Once the string is encoded, we need to write a decode function to generate
original string so need to also store end of a word indicator.
*/

#define DELIMITER 27
class Solution
{
  public:
	static int encode(char **inputArray, int n, char *strEncoded)
	{
		char *word;
		int bit_index = 0;
		int8_t encoded_char;
		uint8_t char_temp;
		int8_t curr_bit_byte;
		int i = 0;
		while (i < n)
		{
			word = (inputArray[i++]);
			do
			{
				encoded_char = (*word - 'a');
				if (encoded_char < 0)
				{
					encoded_char = DELIMITER;
				}
				curr_bit_byte = 3 - bit_index % 8;
				if (curr_bit_byte < 0)
				{
					char_temp = encoded_char >> (-1 * curr_bit_byte);
					strEncoded[bit_index / 8] |= char_temp;
					char_temp = encoded_char << (8 + curr_bit_byte);
					strEncoded[bit_index / 8 + 1] |= char_temp;
				}
				else
				{
					char_temp = encoded_char << (curr_bit_byte);
					strEncoded[bit_index / 8] |= char_temp;
				}
				bit_index += 5;
			} while (*(word++));
		}
		return bit_index;
	}

	static int decode(char **outputArray, int n, char *inputStr)
	{
		char *word;
		int bit_index = 0;
		uint8_t char_temp;
		int8_t shift_bit;
		int i = 0;
		word = outputArray[i];
		uint8_t byte, prev_byte = 0;
		char temp;
		// 10011 000  10
		while (*(inputStr))
		{
			byte = *(inputStr);
			shift_bit = 3 - bit_index % 8;

			if (shift_bit >= 0)
			{
				char_temp = byte >> shift_bit;
				prev_byte = byte;
				inputStr++;
			}
			else
			{
				char_temp = prev_byte << -1 * shift_bit;
				temp = byte >> (8 + shift_bit);
				char_temp |= temp;
				if (8 + shift_bit < 5)
				{
					prev_byte = byte;
					inputStr++;
				}
			}
			char_temp &= 0x1F;

			if (char_temp == DELIMITER)
			{
				*word = 0;
				i++;
				word = (outputArray[i]);
			}
			else
			{
				*word = char_temp + 'a';
				word++;
			}
			bit_index += 5;
		}
		return bit_index;
	}
};

int main()
{
	int const SIZE = 5;
	const char *inputArray[SIZE] = {"this", "is", "an", "input", "string"};
	int input_size = 0;
	int output_size = 0;
	const char *word;

	/* Compute the input size from input Array */
	for (int i = 0; i < SIZE; i++)
	{
		word = (inputArray[i]);
		while (*(word++))
		{
			input_size++;
		}
	}
	input_size = input_size + SIZE;

	/* Compute the output size using 8bit to 5bit conversion + word delimiter */
	output_size = (input_size * 5) / 8 + (((input_size * 5) % 8) == 0 ? 0 : 1);
	cout << "Input Size: " << input_size << endl;
	cout << "Output Size: " << output_size << endl;

	/* Create array for storing encoded buffer */
	char encodedArray[output_size + 1] = {0};

	/* Create array for decoded data */
	char *decodedArray[SIZE];

	/* Allocate 10byte to each word. Assuming word is less than 10byte */
	for (int i = 0; i < SIZE; i++)
	{
		decodedArray[i] = new char[10];
	}

	Solution::encode((char **)inputArray, SIZE, encodedArray);
	encodedArray[output_size] = 0; /* Null terminator */

	Solution::decode(decodedArray, SIZE, encodedArray);
	char *temp;

	/* Print encoded bytes */
	temp = encodedArray;
	cout << "Encoded bytes: [";
	while (*temp)
	{
		cout << hex << setw(2) << setfill('0') << (int)(0xFF & *(temp++))
			 << " ";
	}
	cout << "]" << endl;

	/* Print decoded bytes */
	cout << "Decoded bytes: [";
	for (int i = 0; i < SIZE; i++)
	{
		temp = decodedArray[i];
		while (*temp)
		{
			cout << hex << setw(2) << setfill('0') << (int)(0xFF & *(temp++))
				 << " ";
		}
		cout << hex << setw(2) << setfill('0') << 0x00 << " ";
	}
	cout << "]" << endl;

	/* Print decoded string */
	cout << "[";
	for (int i = 0; i < SIZE - 1; i++)
	{
		cout << decodedArray[i] << ", ";
	}
	cout << decodedArray[SIZE - 1] << "]" << endl;

	/* deallocate memory */
	for (int i = 0; i < SIZE; i++)
	{
		delete[] decodedArray[i];
	}
	return 0;
}
