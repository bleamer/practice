#include <iostream>
#include <string>
#include <cstddef>
#include <cstdlib>

using namespace std;

static const int ALPHABET_SIZE = 26;

static int charToAscii(char key){
	char tempKey = tolower(key);
	if (tempKey < 'a' || tempKey > 'z')
		return 0;
	return (tempKey - 'a');
}

class Trie{
	private:
		Trie * child[ALPHABET_SIZE];
		bool isLeaf;
	public:
		static Trie * newNode();
		void insert (Trie * root, const string key);
		bool search (Trie * root, const string key);
};

Trie * Trie::newNode(){
	Trie * node = new Trie();
	for (int i = 0; i < ALPHABET_SIZE; ++i)
	{
		node->child[i] = (Trie *)NULL;
	}
	node->isLeaf = false;
	return node;
}

void Trie::insert(Trie * root, const string key){
	int level;
	int length = key.size();
	int index;
	Trie * curPtr = root;
	// cout << "Adding new subtrie" << endl;
	for (int i = 0; i < length; ++i)
	{
		index = charToAscii(key.at(i));
		cout << "INS index = "<< index << "   key at "<< key.at(i) << endl;
		if(! curPtr->child[index])	// If children does not exist
			curPtr->child[index] = newNode();
		curPtr =  curPtr->child[index];
		curPtr->isLeaf = true;

	}
	cout << "key = "<< key << "  ptr = "<< curPtr << " is leaf = " << curPtr->isLeaf << endl;
}

bool Trie::search(Trie * root, const string key){
	int level;
	int length = key.size();
	int index;
	Trie * curPtr = root;
	for (int i = 0; i < length; ++i)			
	{
		index = charToAscii(key.at(i));
		cout << "Reached here for key = "<<  key << ",  char = "<<key.at(i) <<endl;
		if(!curPtr->child[index])	// If children does not exist
		{
			return false;
		}
		curPtr = curPtr->child[index];
	}

	cout << "Finished here for key = "<<  key << " isLeaf -> " << curPtr->isLeaf << " ptr = "<< curPtr << endl;
	return (curPtr->isLeaf);
}


int main(int argc, char const *argv[])
{
	string keys[] = {"Hello", "Brother","Cow", "buffallo", "milk","world","there", "here"};
	char output[][32] = {"Not present in trie", "Present in trie"};
	Trie * root =  new Trie();
	for (int i = 0; i < sizeof(keys)/sizeof(keys[0]); ++i)
	{
		root->insert(root, keys[i]);
	}

	   // Search for different keys
    cout << "the" << " ---- " << output[root->search(root, "the")] << endl;
    cout << "these"<< " ---- " <<output[root->search(root, "these")] << endl;
    cout << "buffallo"<< " ---- " <<output[root->search(root, "buffallo")] << endl;
    cout << "thaw"<< " ---- " <<output[root->search(root, "thaw")] << endl;
	return 0;
}