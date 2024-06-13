#include <bits/stdc++.h>
using namespace std;

char getAlphabeticValue(int num)
{
    num = num % 26; // Ensure num is within the range 0-25
    return 'A' + num;
}

int power(int rawPower)
{
    if (rawPower % 2 == 0)
    {
        return (rawPower * 108 / 100);
    }
    else
    {
        return (rawPower * 115 / 100);
    }
}

struct AVLNode
{
    int data, power;
    AVLNode *left, *right;
    int height;
};

struct AVL
{
private:
    AVLNode *_root;
    unsigned _size;

    AVLNode *_avl_createNode(int power, int value)
    {
        AVLNode *newNode = new AVLNode;
        newNode->data = value;
        newNode->power = power;
        newNode->height = 1;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    AVLNode *_search(AVLNode *root, int value)
    {
        while (root != NULL)
        {
            if (value < root->data)
                root = root->left;
            else if (value > root->data)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    int _getHeight(AVLNode *node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int _max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    AVLNode *_rightRotate(AVLNode *pivotNode)
    {
        AVLNode *newParrent = pivotNode->left;
        pivotNode->left = newParrent->right;
        newParrent->right = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left),
                                 _getHeight(pivotNode->right)) +
                            1;
        newParrent->height = _max(_getHeight(newParrent->left),
                                  _getHeight(newParrent->right)) +
                             1;

        return newParrent;
    }

    AVLNode *_leftRotate(AVLNode *pivotNode)
    {
        AVLNode *newParrent = pivotNode->right;
        pivotNode->right = newParrent->left;
        newParrent->left = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left),
                                 _getHeight(pivotNode->right)) +
                            1;
        newParrent->height = _max(_getHeight(newParrent->left),
                                  _getHeight(newParrent->right)) +
                             1;

        return newParrent;
    }

    AVLNode *_leftCaseRotate(AVLNode *node)
    {
        return _rightRotate(node);
    }

    AVLNode *_rightCaseRotate(AVLNode *node)
    {
        return _leftRotate(node);
    }

    AVLNode *_leftRightCaseRotate(AVLNode *node)
    {
        node->left = _leftRotate(node->left);
        return _rightRotate(node);
    }

    AVLNode *_rightLeftCaseRotate(AVLNode *node)
    {
        node->right = _rightRotate(node->right);
        return _leftRotate(node);
    }

    int _getBalanceFactor(AVLNode *node)
    {
        if (node == NULL)
            return 0;
        return _getHeight(node->left) - _getHeight(node->right);
    }

    AVLNode *_insert_AVL(AVLNode *node, int value, int power)
    {

        if (node == NULL)
            return _avl_createNode(power, value);
        if (value < node->data)
            node->left = _insert_AVL(node->left, value, power);
        else if (value > node->data)
            node->right = _insert_AVL(node->right, value, power);

        node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));

        int balanceFactor = _getBalanceFactor(node);

        if (balanceFactor > 1 && value < node->left->data)
            return _leftCaseRotate(node);
        if (balanceFactor > 1 && value > node->left->data)
            return _leftRightCaseRotate(node);
        if (balanceFactor < -1 && value > node->right->data)
            return _rightCaseRotate(node);
        if (balanceFactor < -1 && value < node->right->data)
            return _rightLeftCaseRotate(node);

        return node;
    }

    AVLNode *_findMinNode(AVLNode *node)
    {
        AVLNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        return currNode;
    }

    AVLNode *_remove_AVL(AVLNode *node, int value)
    {
        if (node == NULL)
            return node;
        if (value > node->data)
            node->right = _remove_AVL(node->right, value);
        else if (value < node->data)
            node->left = _remove_AVL(node->left, value);
        else
        {
            AVLNode *temp;
            if ((node->left == NULL) || (node->right == NULL))
            {
                temp = NULL;
                if (node->left == NULL)
                    temp = node->right;
                else if (node->right == NULL)
                    temp = node->left;

                if (temp == NULL)
                {
                    temp = node;
                    node = NULL;
                }
                else
                    *node = *temp;

                free(temp);
            }
            else
            {
                temp = _findMinNode(node->right);
                node->data = temp->data;
                node->right = _remove_AVL(node->right, temp->data);
            }
        }

        if (node == NULL)
            return node;

        node->height = _max(_getHeight(node->left), _getHeight(node->right)) + 1;

        int balanceFactor = _getBalanceFactor(node);

        if (balanceFactor > 1 && _getBalanceFactor(node->left) >= 0)
            return _leftCaseRotate(node);

        if (balanceFactor > 1 && _getBalanceFactor(node->left) < 0)
            return _leftRightCaseRotate(node);

        if (balanceFactor < -1 && _getBalanceFactor(node->right) <= 0)
            return _rightCaseRotate(node);

        if (balanceFactor < -1 && _getBalanceFactor(node->right) > 0)
            return _rightLeftCaseRotate(node);

        return node;
    }

    void _inorder(AVLNode *node)
    {
        if (node)
        {
            _inorder(node->left);
            printf("%d ", node->data);
            _inorder(node->right);
        }
    }

public:
    void init()
    {
        _root = NULL;
        _size = 0U;
    }

    bool isEmpty()
    {
        return _root == NULL;
    }

    AVLNode *getRoot()
    {
        return _root;
    }

    bool find(int value)
    {
        AVLNode *temp = _search(_root, value);
        if (temp == NULL)
            return false;

        if (temp->data == value)
            return true;
        else
            return false;
    }

    void insert(int value, int power)
    {
        if (!find(value))
        {
            _root = _insert_AVL(_root, value, power);
            _size++;
        }
    }

    void remove(int value)
    {
        if (find(value))
        {
            _root = _remove_AVL(_root, value);
            _size--;
        }
    }

    void inorder()
    {
        this->_inorder(_root);
    }

    int getLevels()
    {
        if (_root == NULL)
        {
            return 0;
        }
        else
        {
            return _root->height + 1;
        }
    }

    void printKthLevel(int k, int stage, int &trailPower, bool &isWin)
    {
        if (_root == NULL)
        {
            return;
        }

        queue<AVLNode *> q;
        q.push(_root);
        int level = 0;

        while (!q.empty())
        {
            int size = q.size();
            level++;

            int powerSum = 0;

            if (level == k)
            {
                for (int i = 0; i < size; i++)
                {
                    AVLNode *node = q.front();
                    q.pop();

                    char monsterId[100];
                    sprintf(monsterId, " %c%d_%d_%d", getAlphabeticValue(i), node->data, stage, i + 1);

                    cout << "Monster" << monsterId << ": " << node->power << endl;
                    powerSum += node->power;

                    if (node->left)
                        q.push(node->left);
                    if (node->right)
                        q.push(node->right);
                }
                cout << endl;

                if (power(trailPower) - powerSum >= 0)
                {
                    isWin = true;
                    trailPower = power(trailPower) - powerSum;
                }
                else
                {
                    isWin = false;
                    trailPower = power(trailPower) - powerSum;

                    // cout << "losing stage : " << stage << endl;
                }
                // cout << "Trail Power: " << trailPower << endl;

                return;
            }

            for (int i = 0; i < size; i++)
            {
                AVLNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
    }
};

void printMain(string region, string trailblazer, int power, string element)
{
    cout << "*****************************************************************************" << endl;
    cout << "Honkai Star Rail Region " << region << endl;
    puts(" ");
    cout << "Trailblazer : " << trailblazer << endl;
    cout << "Element : " << element << " - " << power << endl;
    cout << "----------------------------------------------------------------------------" << endl;
}

void result(bool isWin, string trailblazer, string region, string stage)
{
    cout << "Result:" << endl;
    if (isWin)
    {
        cout << trailblazer << " menang melawan Final Boss dan memenangkan game di Honkai Star Rail Region " << region << endl;
    }
    else
    {
        cout << trailblazer << " kalah dan mati di Region " << region << " pada " << stage << endl;
    }
    cout << "*****************************************************************************";
}

void stage(int power, int level, int kth)
{
    cout << "Stage " << level << ":" << endl;
}

int main()
{
    string trailblazer, element, region;
    int n, x;

    AVL set;
    set.init();

    cin >> trailblazer >> n >> element >> x >> region;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        // insert(power, identifier)
        // karena balancingnya via id, yang harus jadi value avl buat balance adalah id
        set.insert(a, b);
    }
    printMain(region, trailblazer, x, element);

    int levels = set.getLevels() - 1;

    int reverseI = levels;
    bool isWin = true;
    int losingStage = 0;

    queue<int> losingArr;

    int i;
    for (i = 1; i <= levels; i++)
    {
        // STAGES SYSTEMS HERE
        if (i == levels)
        {
            // BOSS
            cout << "Final Stage:" << endl;
            cout << "Final Boss " << region << "_" << set.getRoot()->data << ": " << set.getRoot()->power << endl
                 << endl;
            continue;
        }

        stage(x, i, reverseI);
        set.printKthLevel(reverseI--, i, x, isWin);

        if (!isWin)
        {
            losingArr.push(i);
        }
    }

    if (losingArr.size() > 0)
    {
        losingStage = losingArr.front();
    }

    // cout << "Losing Stage: " << losingStage << endl
    //      << endl;

    // BOSS CALCULATION ALGORITHM
    x = power(x);
    int bossPower = set.getRoot()->power;
    bool defeatedAtStage = false;
    string losingStages;

    if (x >= bossPower)
    {
        isWin = true;
    }
    else
    {
        isWin = false;
        losingStages = "Final Stage";
    }
    // END OF BOSS CALCULATION ALGORITHM

    if (losingStage != 0)
    {
        losingStages = "Stage " + to_string(losingStage);
    }

    result(isWin, trailblazer, region, losingStages);
}