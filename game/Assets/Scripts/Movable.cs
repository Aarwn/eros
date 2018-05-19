using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Scripting.APIUpdating;

public abstract class Movable : MonoBehaviour
{

	public float move_time = 0.1f;

	public LayerMask blocking_layer;

	private BoxCollider2D box_collider;
	private Rigidbody2D rb2d;
	private float inv_move_time;
	
	// Use this for initialization
	protected virtual void Start()
	{
		box_collider = GetComponent<BoxCollider2D>();
		rb2d = GetComponent<Rigidbody2D>();
		inv_move_time = 1f / move_time;
	}

	protected bool Move(int xdir, int ydir, out RaycastHit2D hit)
	{
		Vector2 start = transform.position;
		Vector2 end = start + new Vector2(xdir, ydir);

		box_collider.enabled = false;
		hit = Physics2D.Linecast(start, end, blocking_layer);
		box_collider.enabled = true;

		if (hit.transform == null)
		{
			StartCoroutine(SmoothMovement(end));
			return true;
		}

		return false;
	}
	
	protected IEnumerator SmoothMovement(Vector3 end)
	{
		float sqr_remaining_dist = (transform.position - end).sqrMagnitude;

		while (sqr_remaining_dist > float.Epsilon)
		{
			Vector3 new_pos = Vector3.MoveTowards(rb2d.position, end, inv_move_time * Time.deltaTime);
			rb2d.MovePosition(new_pos);
			sqr_remaining_dist = (transform.position - end).sqrMagnitude;
			yield return null;
		}
	}

	protected virtual void AttemptMove<T>(int xdir, int ydir)
		where T : Component

	{
		RaycastHit2D hit;
		bool can_move = Move(xdir, ydir, out hit);
		
		if (hit.transform == null)
			return;

		T hit_component = hit.transform.GetComponent<T>();
		
		if (!can_move && hit_component != null)
			OnCantMove(hit_component);
		
		

	}
	protected abstract void OnCantMove<T>(T component)
		where T : Component;
}
