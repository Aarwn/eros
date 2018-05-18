using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameMngr : MonoBehaviour
{

	public BoardMngr board_script;

	private int lvl = 3;

	void Awake()
	{
		board_script = GetComponent<BoardMngr>();
		InitGame();
	}

	void InitGame()
	{
		board_script.SetupScene(lvl);
		
	}
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
