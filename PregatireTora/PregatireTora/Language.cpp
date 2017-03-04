#include "Language.h"

/*
Se consider? o limb? a c?rei alfabet are c?consoane ?i v?vocale, iar lungimea unui cuvânt este exact l?.
S? se scrie un subprogram cât mai eficient din punct de vedere al timpului de execu?ie, care pentru o
pereche (c, v, l) determin? num?rul maxim de cuvinte care se pot forma ?inând cont de constrângile:
	? un cuvânt este format din litere. O liter? poate fi vocal? sau consoan?.
	? orice consoan? este urmat? de o vocal?. Din aceast? regul? deducem ?i faptul c? un cuvânt nu se
poate termina cu o consoan?.
De exemplu, pentru (c, v, l) = (1, 1, 4), num?rul de cuvinte este care se pot forma conform enun?ului
este 5. Dac? vocala este a??i consoana este b?, cele 5 cuvinte sunt: aaaa, aaba, abaa, baaa, baba.
*/

typedef enum { Vowel, Consonant, NIL } Letter;

int calculateNumberOfWords(int c, int v, Letter lastLetter, int currLen, int len) {
	if (currLen == len - 1) 
		return v;
	else if (currLen < len - 1) {
		if (lastLetter == Consonant) {
			if (v > 0)
				return v * calculateNumberOfWords(c, v, Vowel, currLen + 1, len);
			else
				return 0;			
		} else if (lastLetter == Vowel) {
			if (c > 0) {
				if (v > 0)
					return c * calculateNumberOfWords(c, v, Consonant, currLen + 1, len) +
						v * calculateNumberOfWords(c, v, Vowel, currLen + 1, len);
				else
					return c * calculateNumberOfWords(c, v, Consonant, currLen + 1, len);
			} else {
				if (v > 0)
					return v * calculateNumberOfWords(c, v, Vowel, currLen + 1, len);
				else
					return 0;
			}
		}
		else {
			if (c > 0) {
				if (v > 0)
					return c * calculateNumberOfWords(c, v, Consonant, currLen + 1, len) +
					v * calculateNumberOfWords(c, v, Vowel, currLen + 1, len);
				else
					return c * calculateNumberOfWords(c, v, Consonant, currLen + 1, len);
			}
			else {
				if (v > 0)
					return v * calculateNumberOfWords(c, v, Vowel, currLen + 1, len);
				else
					return 0;
			}
		}
	}
}

int numberOfWords(int ncons, int nvow, int len) {
	return calculateNumberOfWords(ncons, nvow, NIL, 0, len);
}