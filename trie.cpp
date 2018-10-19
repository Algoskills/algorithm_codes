#include <iostream>

using namespace std;

const int COUNTS=52;

//trie node
struct TrieNode
{
	struct TrieNode *children[COUNTS];

	int Endofword;
};

//To make a new node
struct TrieNode *getNode()
{
	struct TrieNode *parent = new TrieNode;
	parent->Endofword = 0;
	for (int i = 0; i < COUNTS; ++i)
	{
		parent->children[i]=NULL;
	}

	return parent;
}

//To inser a string
void insert(TrieNode *root, string word)
{
	struct TrieNode *iterate = root;

	for (int i = 0; i < word.length(); ++i)
	{
		int index= word[i]-'a';
		if(!iterate->children[index])
			iterate->children[index]=getNode();
		iterate=iterate->children[index];
	}

	iterate->Endofword+=1;
}

//To return the no of occurences of string
int search(TrieNode *root, string word)
{
	struct TrieNode *iterate = root;

	for (int i = 0; i < word.length(); ++i)
	{
		int index=word[i]-'a';
		if(!iterate->children[index])
			return 0;
		iterate=iterate->children[index];
	}
	
	return iterate->Endofword;
	
}

//driver function
int main()
{
	string words[] = {"pqrs","pssr","psst","pqrt","pqrs"};

	int noOfwords= sizeof(words)/sizeof(words[0]);

	TrieNode *root=getNode();

	for (int i = 0; i < noOfwords; ++i)
	{
		insert(root,words[i]);
	}

	cout<<"No. of occurences of pqrs is "<<search(root,"pqrs")<<endl;
	

	return 0;
}