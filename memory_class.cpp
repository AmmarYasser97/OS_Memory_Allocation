#include <string>
#include <vector>

struct segment{
	unsigned int start,size,end;
	bool type;
	string name;
};
struct process{
	vector<segment> segments;
	string name;
};
class memory{
private:
	vector<segment> holes;
	static int hole_id =0;
	static int process_id =0;
	vector<process> processes;
	unsigned int mem_size;
public:
	segment add_segment(int start, int size, string name ,bool type){
		segment temp;
		temp.start= start;
		temp.size=size;
		temp.name=name;
		temp.type=type;
		temp.end=start+size;
		return temp;
	}
	void add_hole(int start, int size, string name ="h"+hole_id){
		hole.push_back(add_segment(start,size,name,0));
	}

	void add_process(int n, string name = "P"+process_id)
		process ptemp;
		for(unsigned int i=0;i<n;i++){
			//input data from user
			ptemp.segments.push_back(add_segment(start,size,name,1);
		}
};