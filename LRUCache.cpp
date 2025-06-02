#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;
struct DLLNode
{
    DLLNode *prevNode;
    DLLNode *nextNode;
    int val; // We only need to store the value into the DLL. We don't need a {K,V}
    DLLNode(int val)
    {
        prevNode = nullptr;
        nextNode = nullptr;
        this->val = val;
    }
    DLLNode()
    {
        prevNode = nullptr;
        nextNode = nullptr;
        this->val = -1;
    }
};

class LRUCache
{
public:
    int capacity;
    DLLNode *head;
    DLLNode *tail;
    unordered_map<int, pair<DLLNode *, int>> umap;

    
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new DLLNode();
        tail = new DLLNode();
        head->nextNode = tail;
        tail->prevNode = head;
    }

    bool addAfterHead(DLLNode *node)
    {
        node->nextNode = head->nextNode;
        node->prevNode = head;
        head->nextNode->prevNode = node;
        head->nextNode = node;
        if (head->nextNode == node)
        {
            return true;
        }
        return false;
    }

    bool put(pair<int, int> k_v)
    {
        // if i find that element already, then update the value to new value
        if (umap.find(k_v.first) != umap.end())
        {
            DLLNode *node = umap[k_v.first].first;
            node->val = k_v.second;
            // Reposition the node
            // In general, what do I do
            node->prevNode->nextNode = node->nextNode;
            node->nextNode->prevNode = node->prevNode;
            bool afterHead = addAfterHead(node);
            if (afterHead)
            {
                cout << "Added after the head as the key is already present   "<<"\n";
            }
            // If the nodes nextnode is already tail

            // If the nodees nextnode in not tail
        }
        else if (capacity > 0 && umap.find(k_v.first) == umap.end())
        {
            DLLNode *newNode = new DLLNode(k_v.first); // I will idenfiy from umap using key
            bool insertedAfterHead = addAfterHead(newNode);
            umap[k_v.first] = make_pair(newNode, k_v.second);// Every single time,I'm creating a new node and inserting it.
            cout<< "Stored " << umap[k_v.first].second<< " in map at " << k_v.first <<"\n";
            capacity--;
        }
        else // Incase of over the size, we need to identity the least recently used, and delete that node, and erase from umap
        {
            DLLNode *deleteNode = tail->prevNode;
            deleteNode->prevNode->nextNode = tail;
            tail->prevNode = deleteNode->prevNode;
            // delete from the umap
            cout<<"Erasing the data in the map {"<< deleteNode->val<<","<< umap[deleteNode->val].second<<"}";
            umap.erase(deleteNode->val);
            delete (deleteNode);

            capacity++;

            // Add the new node
            DLLNode *newNode = new DLLNode(k_v.first); // I will idenfiy from umap using key
            bool insertedAfterHead = addAfterHead(newNode);
            umap[k_v.first] = make_pair(newNode, k_v.second); // Every single time,I'm creating a new node and inserting it.
            cout<< "Stored " << umap[k_v.first].second << " in map at " << k_v.first<<"\n";
            capacity--;
        }
        return true;
    }

    int get(int key)
    {
        if (umap.find(key) != umap.end())
        {
            DLLNode *node = umap[key].first;
            node->prevNode->nextNode = node->nextNode;
            node->nextNode->prevNode = node->prevNode;
            bool addedAfterNode = addAfterHead(node);
            if (addedAfterNode)
            {
                cout << "Added after head" <<"\n";
            }
            else
            {
                cout << "There is an issue in 'get' to addAfterHead"<<"\n";
            }
            return umap[key].second;
        }
        return -1;
    }


    void printLRUCache()
    {
        DLLNode* temp = head;
        cout<<"The data in the LRUCache is: "<<"\n";
        while(temp!=nullptr)
        {
            cout<<temp->val<<"\n";
            temp = temp->nextNode;
        }
    }
};

int main()
{
    LRUCache* ob = new LRUCache(2);
    string input[10] = {"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get" };
    int key, value;
    for (int i = 0; i < 10; i++)
    {

        if (input[i] == "put")
        {

            cout<<"Enter the Key: "; cin >>  key;
            cout<<"\n";
            cout<< "Enter the value: "; cin>> value;
            cout<<"\n";
            ob->put(make_pair(key, value));
            ob->printLRUCache();
        }
        if(input[i] == "get")
        {
            cout<<"Get the value for Key: "; cin >>  key;
            cout << ob->get(key);
            cout<<"\n";
            cout<<"Done princting";
            ob->printLRUCache();
        }
    }
    return 0;
}