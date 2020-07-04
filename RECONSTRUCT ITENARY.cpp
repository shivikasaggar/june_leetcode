//Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], 
//reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string> > m;
        if(tickets.size()==0){
            return {};
        }
        for(auto t:tickets){
            m[t[0]].insert(t[1]);
            
        }
        stack<string>s;
        vector<string>v;
        s.push("JFK");
        while(!s.empty()){
            string to=s.top();
            if(m[to].empty()){
                v.push_back(to);
                s.pop();
            }
            else {
				
				s.push(*(m[to].begin()));
				m[to].erase(m[to].begin());
			}
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
