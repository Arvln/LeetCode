class Solution {
    unordered_map<Node*, Node*>visited;
public:
    Node* cloneGraph(Node* node) {
        if (node==NULL) return NULL;
        if (visited.find(node)!=visited.end()) return visited[node];

        Node* newNode=new Node(node->val);
        visited[node]=newNode;
        for (Node* cur : node->neighbors)
            newNode->neighbors.push_back(cloneGraph(cur));
        return newNode;
    }
};