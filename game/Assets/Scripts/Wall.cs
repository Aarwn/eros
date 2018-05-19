using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Wall : MonoBehaviour
{

	public Sprite dmg_sprite;
	public int hp = 4;


	private SpriteRenderer sprite_rndr;
	// Use this for initialization
	void Awake ()
	{
		sprite_rndr = GetComponent<SpriteRenderer>();
	}

	public void DamageWall(int loss)
	{
		sprite_rndr.sprite = dmg_sprite;
		hp -= loss;
		if (hp == 0)
			gameObject.SetActive(false);
	}
}
