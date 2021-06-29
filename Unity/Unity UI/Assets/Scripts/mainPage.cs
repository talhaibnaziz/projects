using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class mainPage : MonoBehaviour {
	public static int pageNo;
	GameObject Page;

	// Use this for initialization
	void Start () {
		mainPage.pageNo = 1;
		Page = GameObject.FindGameObjectWithTag ("nextPage");
	}
	
	// Update is called once per frame
	void Update () {
		Debug.Log (pageNo);
		if (pageNo == 1)
			Page.SetActive (false);
		else {
			//Debug.Log ("working");
			Page.SetActive (true);
		}
	}
}
