class Solution {
public:
    int time_eat(vector<int>& piles,int eat_speed){
        int time=0;
        int size=piles.size();
        for(int i=0;i<size;i++){
            if(piles[i]%eat_speed==0){
                time+=(piles[i]/eat_speed);
            }else{
                time+=(piles[i]/eat_speed);
                time+=1;
            }
        }
        return time;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        //check if possible for various speeds
        int size=piles.size();
        double sum=0;
        int max=0;
        
        //find the minimum and maximum value of speed 
        for(int i=0;i<size;i++){
            if(piles[i]>max){
                max=piles[i];
            }
            sum+=piles[i];
        }
        
        //in max speed takes 'size' amount of hrs
        //in min speed takes >=h hrs
        int max_speed=max;
        int start_speed=int (sum/h);
        
        //if at max speed she cant finish within h hrs,then error
        if(size>h){
            return -1;
        }
        
        if(start_speed==0){
            start_speed=1;
        }
        int mid_speed;
        double sum_speed;
        while(start_speed<=max_speed){
            sum_speed=(max_speed+start_speed);
            mid_speed=int (sum_speed/2);
            //if time to eat at mid speed<=h max_speed=mid_speed-1
            if(time_eat(piles,mid_speed)<=h){
                max_speed=mid_speed-1;
            }else{
                start_speed=mid_speed+1;
            }
        }
        return start_speed;
    }
};
