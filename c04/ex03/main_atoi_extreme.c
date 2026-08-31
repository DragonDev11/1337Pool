#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int	ft_atoi(char *str);

void	print_header(void)
{
	printf("\033[35m");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣷⢸⣿⣿⡜⢯⣷⡌⡻⣿⣿⣿⣆⢈⠻⠿⢿⣿⣿⣿⣿⣿⣿⣷⣦⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡁⢳⣿⣿⣿⣿⣿⣿⡜⣿⣿⣧⢀⢻⣷⠰⠈⢿⣿⣿⣧⢣⠉⠑⠪⢙⠿⠿⠿⠿⠿⠿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣱⡇⡞⣿⣿⣿⣿⣿⣿⡇⣿⣿⡏⡄⣧⠹⡇⠧⠈⢻⣿⣿⡇⢧⢢⠀⠀⠑⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣇⢃⢿⣿⣿⣿⣿⣿⣷⣿⣿⠇⢃⣡⣤⡹⠐⣿⣀⢻⣿⣿⢸⡎⠳⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣾⣿⣿⠘⡸⣿⣿⣿⣿⣿⣿⣿⡿⣰⣿⣿⢟⡷⠈⠋⠃⠎⢿⣿⡏⣿⠀⠘⢆⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⡐⢹⣿⣿⡐⢡⢹⣿⣿⣿⣿⡏⣿⢣⣿⣿⡑⠁⠔⠀⠉⠉⠢⡘⣿⡇⣿⡇⠀⡀⠡⡀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠘⣿⣿⣇⠇⢣⢻⣿⣿⣿⡇⢇⣾⣿⣿⡆⢸⣤⡀⠚⢂⠀⢡⢿⡇⣿⡇⠀⢿⠀⠀⠄⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠠⠹⣿⣿⡘⣆⢣⠻⣿⣿⢈⣾⣿⣿⣿⣶⣸⣏⢀⣬⣋⡼⣠⢸⢹⣿⡇⢠⣼⠙⡄⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠁⠹⣿⣇⠹⡃⠃⠙⡇⠘⢿⣿⣿⣿⣿⣿⣏⣓⣉⣭⣴⣿⠘⢸⣿⠁⠘⠋⠀⠹⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⠀⠀⠈⢿⣇⠂⣷⠄⠐⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⡏⠀⢀⣠⣴⣾⣿⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢆⠀⠀⠀⠙⠆⠈⠢⠲⠥⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡞⣸⠁⠀⢸⣿⣿⣿⣿⣿⣿⡆⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠄⠃⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⡏⠹⣿⣿⡿⠫⠊⠀⠀⠀⣶⠀⢻⣿⣿⣿⣿⡿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⠻⠿⠿⠿⢋⠀⠀⠀⠀⢀⣼⣿⡆⠈⣿⣿⣿⡟⣱⡷⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢁⣁⡀⠨⣛⠿⠶⠄⢀⣠⣾⣿⣿⣷⠀⢹⣿⡟⣴⠈⢃⣶⠔⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⡄⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠈⣿⣿⡿⠀⡀⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢙⠻⣿⣿⢀⠙⠻⠿⣿⣿⣿⣿⣿⣿⡇⠁⣿⠟⡀⠈⣧⢰⣿⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠿⠴⠮⣥⠻⢧⣤⣄⣀⡉⢩⣭⣍⣃⣀⣩⠎⢀⣼⠉⣼⡯⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⠁⣛⠓⢒⣒⣢⡭⢁⡈⠿⠿⠟⠹⠛⠁⠀⠀⠀⠰⠃⠂⠀⠀⠀\n");
	printf("\033[0m\n");
}

int	run_test(int num, char *desc, char *input, int expected)
{
	int	result;
	int	passed;

	result = ft_atoi(input);
	passed = (result == expected);
	printf("  [Test %02d] %-48s ", num, desc);
	if (passed)
	{
		printf("[\033[32mPASS\033[0m]\n");
		return (1);
	}
	else
	{
		printf("[\033[31mFAIL\033[0m] ❌\n");
		printf("    ├── Escaped Input : \"");
		for (int i = 0; input[i]; i++)
		{
			if (input[i] == '\t') printf("\\t");
			else if (input[i] == '\n') printf("\\n");
			else if (input[i] == '\v') printf("\\v");
			else if (input[i] == '\f') printf("\\f");
			else if (input[i] == '\r') printf("\\r");
			else printf("%c", input[i]);
		}
		printf("\"\n");
		printf("    ├── Expected      : %d\n", expected);
		printf("    └── Got           : %d\n\n", result);
		return (0);
	}
}

int	main(void)
{
	int	score = 0;
	int	total = 75;

	print_header();
	printf("⚡ 💀 𝓜𝓞𝓊𝓛𝓘𝓝𝓔𝓣𝓣𝓔 𝓔𝓯𝓗𝓐𝓊𝓢𝓣𝓘𝓥𝓔 𝓐𝓣𝓞𝓘 𝓓𝓔𝓐𝓣𝓗𝓣𝓔𝓢𝓣 (V2.0) 💀 ⚡\n");
	printf("=================================================================\n\n");

	// --- GROUP 1: Standard Core Functional Behavior ---
	score += run_test(1,  "Standard positive", "42", 42);
	score += run_test(2,  "Standard negative", "-42", -42);
	score += run_test(3,  "Zero value", "0", 0);
	score += run_test(4,  "Negative zero", "-0", 0);
	score += run_test(5,  "Positive zero", "+0", 0);
	score += run_test(6,  "Large positive number", "123456789", 123456789);

	// --- GROUP 2: Strict White Space Compliance ---
	score += run_test(7,  "Leading spaces", "   42", 42);
	score += run_test(8,  "Leading horizontal tab (\\t)", "\t42", 42);
	score += run_test(9,  "Leading line feed (\\n)", "\n42", 42);
	score += run_test(10, "Leading vertical tab (\\v)", "\v42", 42);
	score += run_test(11, "Leading form feed (\\f)", "\f42", 42);
	score += run_test(12, "Leading carriage return (\\r)", "\r42", 42);
	score += run_test(13, "All whitespaces sequence", " \t\n\v\f\r42", 42);

	// --- GROUP 3: FORBIDDEN Whitespace Violations ---
	score += run_test(14, "Forbidden ASCII 8 (\\b / backspace)", "\b42", 0);
	score += run_test(15, "Forbidden ASCII 14 (Shift Out)", "\01642", 0);
	score += run_test(16, "Forbidden ASCII 27 (ESC)", "\03342", 0);
	score += run_test(17, "Forbidden ASCII 31 (Unit Separator)", "\03742", 0);

	// --- GROUP 4: 42 Piscine Sign Stacking Matrix ---
	score += run_test(18, "Triple negative (---42)", "---42", -42);
	score += run_test(19, "Double negative (--42)", "--42", 42);
	score += run_test(20, "Single plus (+42)", "+42", 42);
	score += run_test(21, "Triple plus (+++42)", "+++42", 42);
	score += run_test(22, "Interleaved odd negative (-+-42)", "-+-42", 42);
	score += run_test(23, "Interleaved even negative (--+-42)", "--+-42", -42);
	score += run_test(24, "Long sign sequence (---+--+42)", "---+--+42", -42);
	score += run_test(25, "10 minus signs", "----------42", 42);

	// --- GROUP 5: Immediate Interruption / Illegal Separators ---
	score += run_test(26, "Space between signs (--- +42)", "--- +42", 0);
	score += run_test(27, "Space between sign and digits (- 42)", "- 42", 0);
	score += run_test(28, "Space between digits (4 2)", "4 2", 4);
	score += run_test(29, "Tab between sign and digits (-\t42)", "-\t42", 0);
	score += run_test(30, "Sign after digit (42+)", "42+", 42);
	score += run_test(31, "Sign after sign after digit (42-+)", "42-+", 42);

	// --- GROUP 6: Non-Digit / Garbage Characters ---
	score += run_test(32, "Letters at start", "a42", 0);
	score += run_test(33, "Letters in middle", "42a56", 42);
	score += run_test(34, "Special characters start", "*42", 0);
	score += run_test(35, "Special characters middle", "42*56", 42);
	score += run_test(36, "Dots / Float representation", "42.56", 42);
	score += run_test(37, "Comma separator", "42,56", 42);
	score += run_test(38, "Plus minus followed by non-digit", "+-a42", 0);

	// --- GROUP 7: Leading Zeroes Padding ---
	score += run_test(39, "Single zero padding", "0042", 42);
	score += run_test(40, "Negative single zero padding", "-0042", -42);
	score += run_test(41, "Massive zero padding", "00000000000000042", 42);
	score += run_test(42, "Only zeros string", "0000000000", 0);
	score += run_test(43, "Signs with only zero string", "---+0000", 0);

	// --- GROUP 8: 32-Bit Signed Integer Boundaries ---
	score += run_test(44, "INT_MAX exact (2147483647)", "2147483647", INT_MAX);
	score += run_test(45, "INT_MIN exact (-2147483648)", "-2147483648", INT_MIN);
	score += run_test(46, "INT_MAX with multiple plus", "+++2147483647", INT_MAX);
	score += run_test(47, "INT_MIN with multiple minus", "---2147483648", INT_MIN);
	score += run_test(48, "INT_MAX with zeroes padding", "0002147483647", INT_MAX);
	score += run_test(49, "INT_MIN with zeroes padding", "-0002147483648", INT_MIN);

	// --- GROUP 9: Strings with Empty or No Numeric Contents ---
	score += run_test(50, "Empty string", "", 0);
	score += run_test(51, "Only single space", " ", 0);
	score += run_test(52, "Only whitespaces", " \t\n\v\f\r ", 0);
	score += run_test(53, "Only signs (no numbers)", "---+--+", 0);
	score += run_test(54, "Only single minus sign", "-", 0);
	score += run_test(55, "Only single plus sign", "+", 0);

	// --- GROUP 10: Structural & Memory Buffer Anomalies ---
	score += run_test(56, "Null-byte immediate terminate", "\0" "42", 0);
	score += run_test(57, "Null-byte in digits", "42\0" "56", 42);
	score += run_test(58, "Null-byte after sign", "+\0" "42", 0);
	score += run_test(59, "Whitespace, sign stack, no digits, garbage", "  --+abc", 0);
	score += run_test(60, "Whitespace, sign stack, zeroes, garbage", "  --+000xyz", 0);

	// --- GROUP 11: OVERFLOW, MASSIVE DIGIT SEQUENCES & ATOI PARITY ---
	char *overflow_1 = "-0002147483648972663972873627";
	score += run_test(61, "Massive overflow negative string", overflow_1, atoi(overflow_1));

	char *overflow_2 = "999999999999999999999999999";
	score += run_test(62, "Massive overflow positive string", overflow_2, atoi(overflow_2));

	char *overflow_3 = "-999999999999999999999999999";
	score += run_test(63, "Massive overflow negative nine string", overflow_3, atoi(overflow_3));

	char *overflow_4 = "0000000000000000000002147483647";
	score += run_test(64, "Massive zero padded INT_MAX", overflow_4, atoi(overflow_4));

	char *overflow_5 = "-000000000000000000002147483648";
	score += run_test(65, "Massive zero padded INT_MIN", overflow_5, atoi(overflow_5));

	char *overflow_6 = "2147483648";
	score += run_test(66, "INT_MAX + 1 overflow", overflow_6, atoi(overflow_6));

	char *overflow_7 = "-2147483649";
	score += run_test(67, "INT_MIN - 1 overflow", overflow_7, atoi(overflow_7));

	char *overflow_8 = "100000000000000000000";
	score += run_test(68, "Power of 10 overflow (10^20)", overflow_8, atoi(overflow_8));

	char *overflow_9 = "-100000000000000000000";
	score += run_test(69, "Negative Power of 10 overflow (-10^20)", overflow_9, atoi(overflow_9));

	char *overflow_10 = "---0002147483648972663972873627";
	score += run_test(70, "Signs stack + massive overflow", overflow_10, -2147483648);

	char *overflow_11 = "++0002147483648972663972873627";
	score += run_test(71, "Plus stack + massive overflow", overflow_11, -2147483648);

	score += run_test(72, "INT_MAX trailing letters", "2147483647abc", 2147483647);
	score += run_test(73, "INT_MIN trailing letters", "-2147483648abc", INT_MIN);
	score += run_test(74, "Overflow trailing spaces", "99999999999   ", atoi("99999999999   "));
	score += run_test(75, "Overflow mixed signs & text", "--+-999999999999abc", atoi("--+-999999999999abc"));

	printf("=================================================================\n");
	printf("📊 Final Test Score: %d / %d\n", score, total);
	if (score == total)
		printf("🎉 CONGRATULATIONS! Your ft_atoi passes all edge & overflow tests! 🎉\n\n");
	else
		printf("⚠️ FIX THE FAILING OVERFLOW TESTS BEFORE RESUBMITTING ⚠️\n\n");

	return (0);
}
