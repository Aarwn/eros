using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : Movable
{

	public int wall_dmg = 1;
	public int pts_per_items = 10;
	public float restart_lvl_delay = 1f;

	private Animator animator;
	private int items;
	
	// Use this for initialization
	protected override void Start ()
	{
		animator = GetComponent<Animator>();
        items = GameMngr.instance.player_item_points;
	}

	private void OnDisable()
	{
        GameMngr.instance.player_item_points = items;
	}

	// Update is called once per frame
	void Update () 
	{
		if (!GameMngr.instance.players_turn) return;

		int horizontal = 0;
		int vertical = 0;

		horizontal = (int) Input.GetAxisRaw("Horizontal");
		vertical = (int) Input.GetAxisRaw("Vertical");

		if (horizontal != 0)
			vertical = 0;
		
		if (horizontal != 0 || vertical != 0)
			AttemptMove<Wall>(horizontal,vertical);
	}

	protected override void AttemptMove<T>(int xdir, int ydir)
	{
		items--;
		animator.SetTrigger("player_right");
		base.AttemptMove<T>(xdir,ydir);
		RaycastHit2D hit;
		CheckIfGameOver();

		GameMngr.instance.players_turn = false;
	}

	private void OnTriggerEnter2D(Collider2D other)
	{
		if (other.CompareTag("exit"))
		{
			Invoke("Restart",restart_lvl_delay);
			enabled = false;
		}
		else if (other.CompareTag("item"))
		{
			items += pts_per_items;
			other.gameObject.SetActive(false);
		}
	}

	protected override void OnCantMove<T>(T component)
	{
		Wall hit_wall = component as Wall;
		hit_wall.DamageWall(wall_dmg);
	}
	
	private void CheckIfGameOver()
	{
		if (items <= 0)
			GameMngr.instance.GameOver();
	}
}
