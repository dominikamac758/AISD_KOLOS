DFS- inorder (:

void dfs(Node* root) {
    if (root == nullptr) return;

    dfs(root->left);
    cout << root->value << " ";
    dfs(root->right);
}

DFS-preorder (korzen->lewy->prawy):

void dfs_preorder(Node* root) {
  if (root == nullptr) return;

  cout << root->value << " ";
  dfs_preorder(root->left);
  dfs_preorder(root->right);
}

DFS-postorder (
BFS:


