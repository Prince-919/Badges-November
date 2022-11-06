struct TrieNode
{
    bool isEnd;
    TrieNode *children[26];
    TrieNode() : isEnd(false)
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }

    ~Trie()
    {
        deleteNode (root);
    }

    void deleteNode(TrieNode *p)
    {
        if (p == NULL)
        {
            return;
        }
        for (int i = 0; i < 26; i++)
        {
            if (p->children[i])
            {
                deleteNode(p->children[i]);
            }
        }

        delete p;
    }

    void add(string str)
    {
        TrieNode *cur = root;
        for (int i = 0; i < str.length(); i++)
        {
            int index = str[i] - 'a';
            if (cur->children[index] == NULL)
            {
                cur->children[index] = new TrieNode();
            }
            cur = cur->children[index];
        }

        cur->isEnd = true;
    }

    TrieNode *root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        Trie tree;
        for (int i = 0; i < words.size(); i++)
        {
            tree.add(words[i]);
        }

        string buf;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visit(tree.root, board, m, n, i, j, buf, result);
            }
        }

        return result; 
    }
    
private:
    void visit(TrieNode *node, vector<vector<char> > &board, int m, int n,
               int row, int column, string buf, vector<string> &result)
        {
            if (node == NULL)
            {
                return;
            }

            if (board[row][column] == '*')
            {
                return;
            }

            int index = board[row][column] - 'a';
            if (node->children[index])
            {
                buf += board[row][column];
            }
            else
            {
                return;
            }
            char value = board[row][column];
            board[row][column] = '*';
            if (node->children[index]->isEnd)
            {
                node->children[index]->isEnd = false;
                result.push_back(buf);
            }

            if (column+1 < n)
            {
                visit(node->children[index], board, m, n, 
                      row, column+1, buf, result);
            }

            if (column-1 >= 0)
            {
                visit(node->children[index], board, m, n, 
                      row, column-1, buf, result);
            }

            if (row-1 >= 0)
            {
                visit(node->children[index], board, m, n,
                      row-1, column, buf, result);
            }

            if (row+1 < m)
            {
                visit(node->children[index], board, m, n, 
                      row+1, column, buf, result);
            }
            board[row][column] = value;
    }
};