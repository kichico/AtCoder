vector<vector<int>> mat(N, vector<int>(M, 0));

for (int i = 0; i < N; ++i) { //O(N)
    for (int j = 0; j < M; ++j) { //O(M)
        mat[i][j] = random(10); //O(1)
    }
}