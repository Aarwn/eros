using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using Random = UnityEngine.Random;

public class BoardMngr : MonoBehaviour {

	[Serializable]
	public class Count
	{
		public int min;
		public int max;

		public Count(int min, int max)
		{
			this.min = min;
			this.max = max;
		}
	}

	public int cols = 8;
	public int rows = 8;
	public Count wall_count = new Count(5,9);
	public Count item_count = new Count(1,5);
		
	public GameObject[] floor_tiles;
	public GameObject[] wall_tiles;
	public GameObject[] item_tiles;

	private Transform board_holder;
	private List<Vector3> grid_positions = new List<Vector3>();

	void InitList()
	{
		grid_positions.Clear();

		for (int x = 1; x < cols - 1; x++)
		{
			for (int y = 1; x < rows - 1; y++)
			{
				grid_positions.Add(new Vector3(x,y,0f));

			}
		}

	}

	void BoardSetup()
	{
		board_holder = new GameObject("Board").transform;
		for (int x = -1; x < cols + 1; x++)
		{
			for (int y = -1; x < rows + 1; y++)
			{
				GameObject to_instantiate = floor_tiles[Random.Range(0, floor_tiles.Length)];
				if (x == -1 || x == cols || y == -1 || y == rows)
				{
					to_instantiate = wall_tiles[Random.Range(0, wall_tiles.Length)];
					GameObject instance = Instantiate(to_instantiate, new Vector3(x,y,0f), Quaternion.identity) as GameObject;

					instance.transform.SetParent(board_holder);
				}
			}
		}
	}

	Vector3 RandomPosition()
	{
		int random_idx = Random.Range(0, grid_positions.Count);
		Vector3 random_position = grid_positions[random_idx];
		grid_positions.RemoveAt(random_idx);
		return random_position;
	}

	void LayOutObjectAtRandom(GameObject[] tile_array, int min, int max)
	{
		int obj_cnt = Random.Range(min, max + 1);
		for (int i = 0; i < obj_cnt; i++)
		{
			Vector3 random_position = RandomPosition();
			GameObject tile_choice = tile_array[Random.Range(0, tile_array.Length)];
			Instantiate(tile_choice, random_position, Quaternion.identity);
		}
	}
	// Use this for initialization
	public void SetupScene(int lvl)
	{
		BoardSetup();
		InitList();
		LayOutObjectAtRandom(wall_tiles,wall_count.min, wall_count.max);
		LayOutObjectAtRandom(item_tiles,item_count.min, item_count.max);
		
	}
	
}
