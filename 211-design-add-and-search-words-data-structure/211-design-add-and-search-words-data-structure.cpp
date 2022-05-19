struct Node
{
    Node *link[26];
    bool flag = false;

    bool isPresent(char ch)
    {
        return (link[ch - 'a'] != NULL);
    }

    void setChar(Node *t, char ch)
    {
        link[ch - 'a'] = t;
    }

    Node* getReference(char ch)
    {
        return link[ch - 'a'];
    }
};

class WordDictionary
{
    public:
        Node * root;
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (temp->isPresent(word[i]) == false)
            {
                Node *r = new Node();
                temp->setChar(r, word[i]);
            }
            temp = temp->getReference(word[i]);
        }
        temp->flag = true;
    }

    bool search(string word)
    {
        return search_(word.c_str(), root);
    }
    bool search_(const char *word, Node *node)
    {

        for (int i = 0; word[i] && node; i++)
        {
            if (word[i] != '.')
            {
                if (node->isPresent(word[i]) == false)
                    return false;
                node = node->getReference(word[i]);
            }
            else
            {
                Node *temp = node;
                for (int j = 0; j < 26; j++)
                {
                    node = temp->link[j];
                    if (search_(word + i + 1, node))
                    {
                        return true;
                    }
                }
            }
        }
        return node && node->flag;
    }
};

/**
 *Your WordDictionary object will be instantiated and called as such:
 *WordDictionary* obj = new WordDictionary();
 *obj->addWord(word);
 *bool param_2 = obj->search(word);
 */