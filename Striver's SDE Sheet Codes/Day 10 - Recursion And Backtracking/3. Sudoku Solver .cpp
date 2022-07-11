#include<bits/stdc++.h>
bool f=1;
bool check(int  mat[9][9]){
    for(int i=0; i<9; i++){
        set<int> st,st2;
        for(int j=0; j<9; j++){
            if(st.find(mat[i][j]) != st.end())
                return false;
            if(st2.find(mat[j][i]) != st2.end())
                return false;
            st.insert(mat[i][j]);
            st2.insert(mat[j][i]);
        }
    }
    for(int i=0; i<9; i+= 3){
        for(int j=0; j<9; j+= 3){
            set<int> st;
            for(int x=i; x < i+3; x++){
                for(int y=j; y <j+3; y++){
                    if(st.find(mat[x][y]) != st.end())
                        return false;
                    st.insert(mat[x][y]);
                }
            }
        }
    }
    return true;
}
vector<int> get(int mat[9][9], int i, int j){
    set<int> pr;
    for(int k=0; k<9; k++){
        if(mat[i][k]) pr.insert(mat[i][k]);
        if(mat[k][j]) pr.insert(mat[k][j]);
    }
    i -= i%3;
    j -= j%3;
    
    for(int x = i; x < i+3;x++)
        for(int y=j; y < j+3; y++)
            if(mat[x][y])
                pr.insert(mat[x][y]);
    
    vector<int> ans;
    for(int id=1; id<=9; id++)
        if(pr.find(id) == pr.end())
            ans.push_back(id);
    return ans;
}

bool isItSudoku(int matrix[9][9]){
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9;j++){
            if(matrix[i][j]) continue;
            
            vector<int> poss = get(matrix,i,j);
            for(auto x : poss){
                int m2[9][9];
                for(int id=0; id<9; id++)
                    for(int jd=0; jd<9; jd++)
                        m2[id][jd] = matrix[id][jd];
                m2[i][j] = x;
                if(isItSudoku(m2)) return true;
            }
            return false;
        }
    }
    return check(matrix);
}
