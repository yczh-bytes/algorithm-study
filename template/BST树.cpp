#include <iostream>
#include <vector>

class BSTtree
{
private:
struct treeNode
{
    int val;
    treeNode* left;
    treeNode* right;
    treeNode(int val):val(val),left(nullptr),right(nullptr){};
};
public:
treeNode* root;
BSTtree():root(nullptr)
{}

//插入函数
void insert(int x)
{
    treeNode* person = nullptr;
    treeNode* cur = root;
    treeNode* newNode =new treeNode(x);
    //如果树为空，直接插入根节点
    if(!root)
    {
        root=newNode;
        return;
    }
    //树不为空
    while(cur)
    {
        person=cur;
        //小于放左子树
        if(x<cur->val)
        {
            cur=cur->left;
        }
        else if(x>cur->val)
        {
            cur=cur->right;
        }
        else
        {
            //不能存重复的
            delete newNode;
            return;
        }
    }
    if(x<cur->val)
    {
        cur->left=newNode;
    }
    else if(x>cur->val)
    {
        cur->right=newNode;
    }
    
}

//删除操作
void remove(int val)
{
    treeNode* person=nullptr;
    treeNode* cur=root;
    //定义是否找到
    bool bound=false;
    if(!root) return;
    //寻找节点
    while(cur&&!bound)
    {
        if(cur->val==val)
        {
            bound=true;
        }
        else if(val<cur->val)
        {
            cur=cur->left;
        }
        else if(val>cur->val)
        {
            cur=cur->right;
        }
        
    }
    if(!bound)return;
    //然后判断该节点是否为叶子节点或者是否有左右子树
    treeNode* replacement = nullptr;
    if(!cur->left&&!cur->right)
    {
        //为叶子节点
        replacement=nullptr;
    }
    else if(!cur->left)
    {
        //只有右子树
        replacement=cur->right;
    }
    else if(!cur->right)
    {
        //只有左子树
        replacement=cur->left;
    }
    else
    {
        //左右子树都存在，找到其后继节点，即右子树最左
        treeNode* successnor = cur->right;
        treeNode* succPerson = cur;
        while(successnor->left)
        {
            succPerson=successnor;
            successnor=successnor->left;
        }
    //将后继节点的值复制到要删除节点
        cur->val=successnor->val;
        //删除succenor节点
        treeNode* succreplace = successnor->right;

        if(succreplace==cur)
        {
            //后继为cur的右子树
            cur->right = succreplace;
        }
        else
        {
            cur->left=succreplace;
        }
        delete successnor;
        return;
    }
    //如果删除的是根节点
    if(!person)
    {
       root = replacement;
    }
    else if(person->left==cur)
    {
        person->left=replacement;
    }
    else if(person->right==cur)
    {
        person->right=replacement;
    }
        delete cur;
}

};

int main()
{
    
    return 0;
}