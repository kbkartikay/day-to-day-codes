

struct node
{
    node* links[26];
    bool flag= false;
    bool isPresent(char x)
    {
        if(links[x-'a']==NULL) return false;
        else return true;
    }
    void add(char x)
    {
        links[x-'a']= new node();
    }
    node* moveToNext(char x)
    {
        return links[x-'a'];
    }
    void endLabel()
    {
        flag=true;
    }
    bool isEnd()
    {
        return flag;
    }
};
class Trie {
private:
    node* root;
public:

    
    Trie() {
        root = new node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        node* curr= root;
        for(char x : word)
        {
            if(!curr->isPresent(x))
            {
                curr->add(x);
            }
            curr = curr->moveToNext(x);
            
        }
        curr->endLabel(); //label the flag true for this node
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* curr= root;
        for(auto x : word)
            {
                if(!curr->isPresent(x))
                {
                    return false;
                }
                curr= curr->moveToNext(x);
            }
        return curr->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
            
        node* curr= root;
        for(auto x : prefix)
        {
            if(!curr->isPresent(x))
                {
                    return false;
                }
            curr= curr->moveToNext(x);
        }
        return true;
    }
};
