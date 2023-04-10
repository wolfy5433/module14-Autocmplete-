#include "Autocomplete.h"

using namespace std;

Dictionary* getNewNode()
{
    struct Dictionary* pNode = new Dictionary;
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        pNode->children[i] = nullptr;
    }

    return pNode;
}

void Insert(Dictionary* root, string key)
{
    Dictionary* node = root;

    for (int i = 0; i < key.length(); ++i)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
        {
            node->children[index] = getNewNode();
        }
        node->children[index]->frequency++;
        node = node->children[index];
    }
    node->isEndOfWord = true;
}


void Recursion(Dictionary* root, char buffer[], int index, string word, vector<string>& correctWords)
{
    if (root == nullptr)
    {
        return;
    }

    if ((root->frequency == 3 || root->frequency == 2 || root->frequency == 1) && (word.size() == index))
    {
        AutocmptMoreRecursion(root, buffer, index, word, correctWords);
        return;
    }

    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        if ((i + 'a' == word[index]) && (root->children[i] != nullptr))
        {
            buffer[index] = i + 'a';
            Recursion(root->children[i], buffer, index + 1, word, correctWords);
        }
    }
}
void AutocmptMoreRecursion(Dictionary* root, char buffer[], int index, string word, vector<string>& correctWords)
{
    if (root->isEndOfWord == true)
    {
        buffer[index] = '\0';
        correctWords.push_back(buffer);
        return;
    }
    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        if (root->children[i] != nullptr)
        {
            buffer[index] = i + 'a';
            AutocmptMoreRecursion(root->children[i], buffer, index + 1, word, correctWords);
        }
    }
}
void Autocomplete(string arr[], int n, string word, vector<string>& correctWords)
{

    Dictionary* root = new Dictionary();
    for (int i = 0; i < n; ++i)
    {
        Insert(root, arr[i]);
    }
    char buffer[1000];
    int index = 0;

    Recursion(root, buffer, index, word, correctWords);
}