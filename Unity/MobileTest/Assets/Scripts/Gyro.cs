﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// Activate head tracking using the gyroscope
public class Gyro : MonoBehaviour {
	public GameObject player; // First Person Controller parent node
	public GameObject head; // First Person Controller camera

	// The initials orientation
	private float initialOrientationX;
	private float initialOrientationY;
	private float initialOrientationZ;

	// Use this for initialization
	void Start () {
		// Activate the gyroscope
		Input.gyro.enabled = true;

		// Save the firsts values
		initialOrientationX = Input.gyro.rotationRateUnbiased.x;
		initialOrientationY = Input.gyro.rotationRateUnbiased.y;
		initialOrientationZ = -Input.gyro.rotationRateUnbiased.z;
	}

	// Update is called once per frame
	void Update () {
		// Rotate the player and head using the gyroscope rotation rate
		head.transform.Rotate (initialOrientationX -Input.gyro.rotationRateUnbiased.x, initialOrientationY -Input.gyro.rotationRateUnbiased.y, 0);
		//head.transform.Rotate (initialOrientationX -Input.gyro.rotationRateUnbiased.x, 0, initialOrientationZ + Input.gyro.rotationRateUnbiased.z);
	}
}
