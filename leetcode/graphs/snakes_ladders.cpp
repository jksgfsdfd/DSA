class Solution {
public:
    pair<int,int> getcoordinates(int num,int size){
        int row = size - 1 - ((num-1)/size);
        int coloumn;
        if(((num-1)/size)%2==0){
            coloumn = (num - 1)%size;
        }else{
            coloumn = size - 1 - ((num - 1)%size) ;
        }
        return {row,coloumn};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        //we start from position 1 and try to reach 36
        //for every element we reach from another element we mark its dist as
        //prev_dist + 1
        int size = board.size();
        pair<int,int> element = {1,0}; //position 1 and dist=0
        queue<pair<int,int>> queue;
        queue.push(element);
        unordered_set<int> reached; //set containing already reached elements
        reached.insert(element.first);
        while(!queue.empty()){
           pair<int,int> ele = queue.front();
            if(ele.first==size*size){
                return ele.second;
            }
            for(int i = ele.first+1 ; i<=ele.first+6 &&  i<=size*size;i++){
                //check board
                pair<int,int> cord = getcoordinates(i,size);
                int x = cord.first;
                int y = cord.second;
                if(board[x][y]==-1){
                    if(reached.find(i)!=reached.end()){
                        continue;
                    }
                    queue.push({i,ele.second+1});
                    reached.insert(i);
                }else{
                    if(reached.find(board[x][y])!=reached.end()){
                        continue;
                    }
                    queue.push({board[x][y],ele.second+1});
                    reached.insert(board[x][y]);
                }
            }
            queue.pop();
        }
        return -1;
        
    }
};
