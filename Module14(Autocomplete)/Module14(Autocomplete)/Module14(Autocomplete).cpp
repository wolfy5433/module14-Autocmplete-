#include "Autocomplete.h"
#include"Vocabulary.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Приветсвую Вас.Добро пожаловать в программу под названием \"Автозаполение\".Все слова вводятся на анлгийском языке!Если вы желаете выйти из программы, то введите \"exit\"" << endl;

	while (message != "exit")
	{
		getline(cin, message);
		for (int i = 0; i < message.length(); ++i)
		{
			if (message[i] == ' ')
			{
				words.push_back(word);
				word.clear();
				++i;
			}
			word += message[i];
		}
		words.push_back(word);

		Autocomplete(vocabulary, n, words[words.size() - 1], correctWords);

		if (!correctWords.empty())
		{
			for (int i = 0; i < correctWords.size(); ++i)
			{
				cout << i + 1 << '-' << correctWords[i] << endl;
			}

			(cin >> choice).get();

			message.clear();

			for (int i = 0; i < words.size() - 1; ++i)
			{
				message = message + words[i] + ' ';
			}
			message += correctWords[choice - 1];

			cout << message << '\n' << endl;

			correctWords.clear();
		}

		words.clear();
		word.clear();
	}

	return 0;
}