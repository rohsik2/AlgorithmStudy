using System;
using System.Collections.Generic;


public class main {
	public static void Main() {
		long n_node = Int64.Parse(Console.ReadLine().Split()[0]);
		string[] user_input1 = Console.ReadLine().Split();
		string[] user_input2 = Console.ReadLine().Split();
		List<int> dists = new List<int>();
		List<int> prices = new List<int>();
		foreach(string dist in user_input1){
			dists.Add(Int32.Parse(dist));
		}
		foreach(string price in user_input2){
			prices.Add(Int32.Parse(price));
		}
		
		long cur_cost = 0;
		long min_price = 987654321;
		for(int i =0 ; i<n_node-1; i++){
			if(min_price > prices[i]){
				min_price = prices[i];
			}
			cur_cost += min_price * dists[i];
		}
		Console.WriteLine(cur_cost);
	
	}
}