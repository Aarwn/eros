using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameMngr : MonoBehaviour
{
	public static GameMngr instance = null;
	public BoardMngr board_script;
	public int player_item_points = 100;
	[HideInInspector] public bool players_turn = true;
	private int lvl = 3;

	void Awake()
	{
		if (instance == null)
			instance = this;
		else if (instance != this)
			Destroy(gameObject);
		
		DontDestroyOnLoad(gameObject);
		board_script = GetComponent<BoardMngr>();
		InitGame();
	}

	void InitGame()
	{
		board_script.SetupScene(lvl);
		
	}

	public void GameOver()
	{
		enabled = false;
	}
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
