using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class pressButton : MonoBehaviour {
	// Use this for initialization
	public void buttonClicked () {
		mainPage.pageNo = 2;
	}
	public void backButtonClicked () {
		mainPage.pageNo = 1;
	}
	void Update () {
		//Debug.Log (mainPage.pageNo);
	}
}
