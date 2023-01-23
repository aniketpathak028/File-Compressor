#include "huffman.hpp"

void huffman::createArr()
{
    for (int i = 0; i < 128; i++)
    {
        arr.push_back(new Node());
        arr[i]->data = i;
        arr[i]->freq = 0;
    }
}

void huffman::traverse(Node *r, string str)
{
    if (r->left == NULL && r->right == NULL)
    {
        r->code = str;
        return;
    }

    traverse(r->left, str + '0');
    traverse(r->right, str + '1');
}

int huffman::binToDec(string inStr)
{
    int res = 0;
    for (auto c : inStr)
    {
        res = res * 2 + c - '0';
    }
    return res;
}

string huffman::decToBin(int inNum)
{
    string temp = "", res = "";
    while (inNum > 0)
    {
        temp += (inNum % 2 + '0');
        inNum /= 2;
    }
    res.append(8 - temp.length(), '0');
    for (int i = temp.length() - 1; i >= 0; i--)
    {
        res += temp[i];
    }
    return res;
}

void huffman::buildTree(char a_code, string &path)
{
    Node *curr = root;
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == '0')
        {
            if (curr->left == NULL)
            {
                curr->left = new Node();
            }
            curr = curr->left;
        }
        else if (path[i] == '1')
        {
            if (curr->right == NULL)
            {
                curr->right = new Node();
            }
            curr = curr->right;
        }
    }
    curr->data = a_code;
}

