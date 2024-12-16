#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include <libintl.h>
#include <argp.h>
#include <locale.h>

/** @file num_guess.c
 * Implementation
 *
 * Guessing your number from 1 to 100.
 */

#define _(STRING) gettext(STRING)

const char *argp_program_version =
  "num-guess 2.28";
const char *argp_program_bug_address =
  "<a@a.com>";

char doc[] =
  "Num-guess - program designed to find number you guessed!";

static char args_doc[] = "";

static struct argp_option options[] = {
  {"roman", 'r', 0, 0, "Use roman system" },
  { 0 }
};

struct arguments {
  char *args[1];
  int roman;
};

static error_t parse_opt (int key, char *arg, struct argp_state *state) {
  struct arguments *arguments = state->input;

  switch (key) {
    case 'r':
      arguments->roman = 1;
      break;

    default:
      return ARGP_ERR_UNKNOWN;
    }
  return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc };

/** Mapping for converting decimal numbers to roman numbers */
char* romans[100] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X",
                     "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX",
                     "XXI", "XXII", "XXIII", "XXIV", "XXV", "XXVI", "XXVII", "XXVIII","XXIX", "XXX",
                     "XXXI", "XXXII", "XXXIII", "XXXIV", "XXXV", "XXXVI", "XXXVII", "XXXVIII", "XXXIX", "XL",
                     "XLI", "XLII", "XLIII", "XLIV", "XLV", "XLVI", "XLVII", "XLVIII", "XLIX", "L",
                     "LI", "LII","LIII", "LIV", "LV", "LVI", "LVII", "LVIII", "LIX", "LX",
                     "LXI", "LXII", "LXIII", "LXIV", "LXV", "LXVI", "LXVII", "LXVIII", "LXIX", "LXX",
                     "LXXI", "LXXII", "LXXIII", "LXXIV", "LXXV", "LXXVI", "LXXVII", "LXXVIII", "LXXIX", "LXXX",
                     "LXXXI", "LXXXII", "LXXXIII", "LXXXIV", "LXXXV", "LXXXVI", "LXXXVII", "LXXXVIII", "LXXXIX", "XC",
                     "XCI", "XCII", "XCIII", "XCIV", "XCV", "XCVI", "XCVII", "XCVIII", "XCIX", "C"};
/** Translate decimal number @p num to roman number
 *
 * @param num decimal number to translate
 * @return roman number
 */
char* to_roman(int num) {
    return (num >= 1 && num <= 100) ? romans[num-1] : "Out of bounds";
}

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "");
    bindtextdomain("num_guess", ".");
    textdomain("num_guess");

    struct arguments arguments;
    arguments.roman = 0;
    argp_parse (&argp, argc, argv, 0, 0, &arguments);

    int left = 1;
    int right = 100;

    printf(_("Guess your number from %d to %d\n"), left, right);
    while (right > left) {
        int mid = (left + right) / 2;
        if (arguments.roman)
            printf(_("Is your number greater than %s? Answer only \"yes\" or \"no\"\n"), to_roman(mid));
        else
            printf(_("Is your number greater than %d? Answer only \"yes\" or \"no\"\n"), mid);

        char ans[10];
        int s = scanf("%s", ans);
        if (!strcmp(ans, _("yes")))
            left = mid + 1;
        else if (!strcmp(ans, _("no")))
            right = mid;
    }
    if (arguments.roman)
        printf(_("Your number is %s!\n"), to_roman(left));
	else
        printf(_("Your number is %d!\n"), left);

    return 0;
}
