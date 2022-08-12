class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i=0;
        int size=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> arr;
        while(i<size){
            int target=(-nums[i]);
            vector<vector<int>> elements;
            elements=pairsum(nums,i+1,target);
            int count=elements.size();
            while(count){
                elements[count-1].push_back(nums[i]);
                count--;
            }
            for(auto x: elements){
                arr.push_back(x);
            }
            while(i<size-1){
                if(nums[i]==nums[i+1]){
                    i++;
                }else{
                    break;
                }
            }
            i++;
        }
        return arr;
    }
    
    vector<vector<int>> pairsum(vector<int> nums,int index,int target){
        unordered_set<int> complis;
        int i=index;
        int size=nums.size();
        vector<vector<int>> pairs;
        while(i<size){
            
            int compli=target-nums[i];
            
            if(complis.find(compli)!=complis.end()){
                vector<int>pair;
                pair.push_back(nums[i]);
                pair.push_back(compli);
                pairs.push_back(pair);
                //complis.insert(nums[i]);
                complis.erase(compli);
                while(i<size-1){
                    if(nums[i]==nums[i+1]){
                        i++;
                    }else{
                        break;
                    }
                }
            }
            
            else{
                complis.insert(nums[i]);
            }
            
            i++;    
        }
        return pairs;
    }
};
