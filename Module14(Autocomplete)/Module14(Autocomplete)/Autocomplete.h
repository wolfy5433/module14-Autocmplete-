#pragma once
#pragma once
#include <iostream>
#include <string>
#include <vector>
#define ALPHABET_SIZE 26

using namespace std;

struct Dictionary
{
	struct Dictionary* children[ALPHABET_SIZE];
	bool isEndOfWord;
	int frequency = 0;
};
Dictionary* getNewNode();
void Insert(Dictionary* root, string key);
void Recursion(Dictionary* root, char buffer[], int index, string word, vector<string>& correctWords);
void AutocmptMoreRecursion(Dictionary* root, char buffer[], int index, string word, vector<string>& correctWords);
void Autocomplete(string arr[], int n, string word, vector<string>& correctWords);