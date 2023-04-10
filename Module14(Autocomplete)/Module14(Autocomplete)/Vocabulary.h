#pragma once
#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <vector>
string vocabulary[] =
{
	"apple", "atmosphere", "astronaut", "avokado", "approach",
	"breath", "banana", "battle", "box",
	"clever", "clock", "cat", "camp", "clown",
	"drinks", "doctor", "drive", "disaster", "dark", "discord",
	"eat","energy","equal",
	"frut","frend","food","fat","frequency",
	"garage","garbage","green","grape",
	"hello","hard","heap","Houston",
	"intrnet","immediatly","instagram",
	"juice","Jack","July"
	"kick","kinder","kangaroo",
	"lemone","link","letter","level",
	"metro","monster","mom","milka",
	"nut","ninja","nintendo","number",
	"orange","Orlando","old","Ostin",
	"parrot","pizza","potato","pinguin",
	"quick","quatro","quiz",
	"rat","rice","risk","random",
	"slack","stack","size","swear","slow",
	"trash","telephone","tornado","table",
};
int n = sizeof(vocabulary) / sizeof(vocabulary[0]);

vector<string> words, correctWords;
string word;
string message;
int choice;