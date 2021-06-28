#include "binarytreegraphic.h"
#include <user.h>
#include <mainwindow.h>
#include <queue>

using namespace std;

void BinaryTreeGraphic::init(QGraphicsScene* scene, QGraphicsView* view){
    this->_root = NULL;
    this->_scene = scene;
    this->_view = view;
}

void BinaryTreeGraphic::insert(int a){
    Node* tmp = new Node;
    tmp->key = a;
    tmp->left = NULL;
    tmp->right = NULL;

    if(this->_root == NULL){
        tmp->p = NULL;
        this->_root = tmp;
        MainWindow::setRootNode(true);
    }else{
        MainWindow::setRootNode(false);
        Node* cElem = this->_root;
        Node* parent = NULL;

        while(cElem != NULL){
            parent = cElem;
            if (a < cElem->key){
                cElem = cElem->left;
            } else {
                cElem = cElem->right;
            }
        }

        tmp->p = parent;
        if(a < parent->key){
            parent->left = tmp;
        }else{
            parent->right = tmp;
        }
    }
}

void BinaryTreeGraphic::preorderWalk(Node* p) {
    if (p != NULL) {
       cout << p->key << " ";
       MainWindow::setItems(p->key);
       this->preorderWalk(p->left);
       this->preorderWalk(p->right);
       return;
    }
}

void BinaryTreeGraphic::preorderWalk(){
    cout << "Preorder walk: ";
    this->preorderWalk(this->_root);
    cout << endl;
}

void BinaryTreeGraphic::postorderWalk(Node* p) {
        if (p != NULL) {
           this->postorderWalk(p->left);
           this->postorderWalk(p->right);
           cout << p->key << " ";
           MainWindow::setItems(p->key);
        }
}

void BinaryTreeGraphic::postorderWalk(){
    cout << "Postorder walk: ";
    this->postorderWalk(this->_root);
    cout << endl;
}

void BinaryTreeGraphic::inorderWalk(Node* p){
        if (p != NULL) {
           this->inorderWalk(p->left);
           cout << p->key << " ";
           MainWindow::setItems(p->key);
           this->inorderWalk(p->right);
        }
}

void BinaryTreeGraphic::inorderWalk(){
    cout << "Inorder walk: ";
    this->inorderWalk(this->_root);
    cout << endl;
}

void BinaryTreeGraphic::breadthfirstWalk(Node *p){
    queue<Node*> q;
    q.push(p);
    while(!q.empty()){
        Node* curr = q.front();
        cout << curr->key << " ";
        MainWindow::setItems(curr->key);
        q.pop();
        if (curr->left != nullptr) q.push(curr->left);
        if (curr->right != nullptr) q.push(curr->right);
        }
}

void BinaryTreeGraphic::breadthfirstWalk(){
    cout << "Breadthfirst walk: ";
    this->breadthfirstWalk(this->_root);
    cout << endl;
}

Node* BinaryTreeGraphic::findElem(int val, Node* p){
    if(p != NULL){

        MainWindow::setSearchItems(p->key);

        if(val == p->key){

            MainWindow::setSearchItems(val);
            if (p->left != NULL && MainWindow::getSuccValue() == -1 && MainWindow::getSearchSig() != -1)
                MainWindow::setInsertItems(p->left->key);
            else if (p->right != NULL && MainWindow::getSuccValue() == -1 && MainWindow::getSearchSig() != -1)
                MainWindow::setInsertItems(p->right->key);
            else
                MainWindow::setSearchSig(-1);

            p->searched = 1;
            return p;
        }

        if(val < p->key){
            return findElem(val, p->left);
        }else{
            return findElem(val, p->right);
        }
    }else{
        return NULL;
    }
}

Node* BinaryTreeGraphic::findElem(int val){
    return this->findElem(val, this->_root);
}

Node* BinaryTreeGraphic::findSuccessor(int val){
    Node* startNode = this->findElem(val);

    startNode = startNode->right;
    while(startNode != NULL && startNode->left != NULL){
        startNode = startNode->left;
    }

    return startNode;
}

int BinaryTreeGraphic::deleteNode(Node* p){
    Node *q = NULL;
    Node *r = NULL;

    if (p == NULL){
        return -1;
    } else {
        if (p->left == NULL || p->right == NULL){
            q = p;
        }else{
            q = this->findSuccessor(p->key);
            MainWindow::setDeleteHolder(q->key);
            MainWindow::setSuccValue(p->key);
        }

        if (q->left != NULL){
            r = q->left;
        }else{
            r = q->right;
        }

        if (r != NULL){
            r->p = q->p;
        }

        if (q->p == NULL){
            this->_root = r;
        }else if (q == q->p->left){
            q->p->left = r;
        }else{
            q->p->right = r;
        }

        if (q != p){
            p->key = q->key;
        }
        return 0;
    }
}

int BinaryTreeGraphic::deleteNode(int val){
    if(this->deleteNode(this->findElem(val)) == -1)
        return -1;
    else
        return 0;
}

vector<int> BinaryTreeGraphic::generateTree(int nodes){
    vector<int> holder;
    for(int i = 0; i < nodes; i++){
        int a = rand() % 100 + 1;
        while(true){
            if (std::find(holder.begin(), holder.end(), a) != holder.end())
                    a = rand() % 100 + 1;
            else
                break;
        }
        holder.push_back(a);
    }
    return holder;
}

void BinaryTreeGraphic::_graphWalk(Node* p, QTextStream *stream) {
    if (p != NULL){

        if (p->searched == 1){
            *stream << "\t\t" << "n" << p->key << "[color=\"green\",label=\"" << p->key << "\"];" << "\n";
        }
        else
            *stream << "\t\t" << "n" << p->key << "[label=\"" << p->key << "\"];" << "\n";

        if(p->left != NULL){
            *stream << "\t\tn" << p->key << "--" << "n" << p->left->key << ";" << "\n";
            this->_graphWalk(p->left, stream);
        }else{
            *stream << "\t\t" << "n" << p->key << "leftNull" << "[style=\"filled\",label=\".\"];" << "\n";
            *stream << "\t\tn" << p->key << "--" << "n" << p->key << "leftNull" << "\n";
        }

        if(p->right != NULL){
            *stream << "\t\tn" << p->key <<  "--" << "n" << p->right->key << ";" << "\n";
            this->_graphWalk(p->right, stream);
        }else{
            *stream << "\t\t" << "n" << p->key << "rightNull" << "[style=\"filled\",label=\".\"];" << "\n";
            *stream << "\t\tn" << p->key << "--" << "n" << p->key << "rightNull" << "\n";
        }
    }
}

QByteArray BinaryTreeGraphic::_prepareGraph(){
    QByteArray a = QByteArray();

    QTextStream stream(&a, QIODevice::ReadWrite);
    stream << "graph ""{" << "\n";
    stream << "\tnode[fontsize=10,margin=0,width=\".4\", height=\".3\"];" << "\n";
    stream << "\tsubgraph cluster17{" << "\n";

    this->_graphWalk(this->_root, &stream);
    stream << "\t}\n" << "}" << "\n";
    stream.flush();

    return a;
}

QPixmap BinaryTreeGraphic::show(){
    QProcess* p = new QProcess();
    QByteArray a = this->_prepareGraph();

    p->setProcessChannelMode(QProcess::MergedChannels);

    // please change the directory path of where you installed graphviz.
    // look for an executable called dot.exe, copy the path and paste it to this
    // line below.

    p->start("C:/Program Files/Graphviz/bin/dot.exe", QStringList() << "-Tpng");
    p->write(a);

    QByteArray data;
    QPixmap pixmap = QPixmap();

    while(p->waitForReadyRead(500)){
        data.append(p->readAll());
    }

    pixmap.loadFromData(data);

    p->close();
    delete(p);
    return pixmap;
}
