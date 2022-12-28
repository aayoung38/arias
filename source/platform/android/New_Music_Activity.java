package com.example.android_progression_generator;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;

public class New_Music_Activity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_new__music_);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.new__music_, menu);
		return true;
	}

}
