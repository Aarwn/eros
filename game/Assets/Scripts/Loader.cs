using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Loader : MonoBehaviour
{

	public GameObject gameMngr;

	private void Awake()
	{
		if (GameMngr.instance == null)
			Instantiate(gameMngr);
	}

	
	// Update is called once per frame
	void Update () {
		
	}
}
