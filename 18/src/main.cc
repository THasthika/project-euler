#include "main.h"

using namespace std;

int main(int argc, char **argv)
{

	int **tree;
	int count;

	get_tree("input.txt", &tree, &count);
	max_path(&tree, count);

	cout << tree[0][0] << endl;

	return 0;
}

void max_path(int ***tree, int count)
{
	int i = count - 1;
	int j = i;
	for( ; i >= 0; j--)
	{
		if(i > 0)
		{
			if(j == i) continue;
			(*tree)[i-1][j] = (*tree)[i-1][j] + max((*tree)[i][j], (*tree)[i][j+1]);
		}
		if(j == 0)
		{
			j = i;
			i--;
		}
	}
}

void get_tree(string filepath, int ***tree, int *count)
{
	ifstream file(filepath);

	int num;
	int i = 0;
	int j = 0;

	int *nums = new int[1];

	while(file >> num)
	{
		nums = (int*)realloc(nums, sizeof(int)*(i+1));
		nums[i] = num;
		i++;
	}

	for(j = 1; i > (j*(j+1))/2; j++) continue;
	*count = j;

	(*tree) = new int*[j];

	i = j = 0;
	int k = 0;

	(*tree)[0] = new int[1];

	while(i < *count)
	{
		if(i < j) {
			j = 0;
			i++;
			if(i == *count) break;
			(*tree)[i] = new int[i+1];
		}
		(*tree)[i][j] = nums[k];
		k++;
		j++;
	}

	file.close();
}