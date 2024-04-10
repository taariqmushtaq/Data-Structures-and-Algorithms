#include <iostream>
#include <algorithm>
using namespace std;

const int SIZE = 26;
string toDecode = "";
class Node
{
public:
	char ch;
	int freq;
	Node *left, *right, *next, *root;
	Node()
	{
		ch = ' ';
		freq = 0;
		root = next = left = right = NULL;
	}
	void makingListToInCode(char chArr[], int fArr[], int count)
	{
		Node *addNode;
		for (int i = 0; i < count; i++)
		{
			addNode = new (Node);
			addNode->ch = chArr[i];
			addNode->freq = fArr[i];
			if (root == NULL)
				root = addNode;
			else
			{
				if (root->freq >= addNode->freq)
				{
					addNode->next = root;
					root = addNode;
				}
				else
				{
					Node *runPtr = root;
					while (runPtr->next != NULL && runPtr->next->freq < addNode->freq)
					{
						runPtr = runPtr->next;
					}
					addNode->next = runPtr->next;
					runPtr->next = addNode;
				}
			}
		}
		CompressText();
	}
	void CompressText()
	{
		Node *newPtr;
		while (root->next != NULL)
		{
			newPtr = new (Node);
			newPtr->left = root;
			newPtr->right = root->next;
			newPtr->freq = newPtr->left->freq + newPtr->right->freq;
			root = root->next->next;
			if (root == NULL)
				root = newPtr;
			else
			{
				if (root->freq > newPtr->freq)
				{
					newPtr->next = root;
					root = newPtr;
				}
				else
				{
					Node *runThis = root;
					while (runThis->next != NULL && runThis->next->freq < newPtr->freq)
					{
						runThis = runThis->next;
					}
					newPtr->next = runThis->next;
					runThis->next = newPtr;
				}
			}
		}
	}
	void disPlay(Node *huffRoot, string str)
	{
		if (huffRoot->left == NULL)
		{
			cout << huffRoot->ch << "   " << str << endl;
			toDecode += str;
			return;
		}
		disPlay(huffRoot->left, str + '0');
		disPlay(huffRoot->right, str + '1');
	}
	void decodedShow(Node *decodeRoot, char check)
	{
		/*cout << check << endl;
		if (check == '0') {
			if (decodeRoot->left == NULL) {
				cout << decodeRoot->ch;
				decodeRoot = root;
				return;
			}
			char c;
			c = toDecode.back();
			toDecode.pop_back();
			decodedShow(decodeRoot->left, c);
		}
		if (check == '1') {
			if (decodeRoot->left == NULL) {
				cout << decodeRoot->ch;
				decodeRoot = root;
				return;
			}
			char c;
			c = toDecode.back();
			toDecode.pop_back();
			decodedShow(decodeRoot->right, c);
		}*/
		if (decodeRoot->left == NULL)
		{
			cout << decodeRoot->ch;
			cout << "Hi i am here" << endl;
			decodeRoot = root;
			return;
		}
		if (check == '0')
		{
			char c;
			c = toDecode.back();
			toDecode.pop_back();
			decodedShow(decodeRoot->left, c);
		}
		if (check == '1')
		{
			char c;
			c = toDecode.back();
			toDecode.pop_back();
			decodedShow(decodeRoot->right, c);
		}
	}
};
int main()
{
	cout << "\t\t--------------------------------------------------" << endl;
	cout << "\t\t         H    I    Z    C O D E R S" << endl;
	cout << "\t\t--------------------------------------------------" << endl;
	cout << endl;
	string text;
	cout << "Enter Code to Compress it: ";
	cin >> text;

	int arr[SIZE], count = 0, fcount = 0, fArr[SIZE];
	char chArr[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = 0;
	}
	for (int i = 0; i < text.length(); i++)
	{
		arr[text[i] - 'a']++;
	}
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] != 0)
		{
			chArr[count++] = i + 'a';
			fArr[fcount++] = arr[i];
			// cout << arr[i] << "  ";
		}
	}
	cout << endl;
	cout << "Char  &  Frequency" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << chArr[i] << "         ";
		cout << fArr[i] << "    ";
		cout << endl;
	}
	cout << endl;
	cout << "HuffMan Code: " << endl;
	Node compression;
	compression.makingListToInCode(chArr, fArr, count);
	compression.disPlay(compression.root, "");
	cout << endl;
	reverse(toDecode.begin(), toDecode.end());
	cout << toDecode << endl;
	/*char c, a;
	c = toDecode.back();
	toDecode.pop_back();*/
	/*cout << c << endl;
	a = toDecode.back();
	cout << a << endl;*/
	// compression.decodedShow(compression.root, c);

	system("pause");
}