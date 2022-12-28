package com.example.android_progression_generator;

//import progression_generator_utilities.Guitar_Tab_Generator;
//import progression_generator_utilities.Major_Scale_Manager;
//import progression_generator_utilities.Scale_Guitar;
//import progression_generator_utilities.Scale_Manager;
import android.app.Activity;
import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.widget.LinearLayout;

public class MainActivity extends Activity {

  public final static String TAB_REPORT_MESSAGE = "com.example.android_progression_generator.TAB_REPORT_MESSAGE";
  public final static String KEY_REPORT_MESSAGE = "com.example.android_progression_generator.KEY_REPORT_MESSAGE";
  
	//GuitarDrawView drawView;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
	
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		//LinearLayout layout = (LinearLayout) findViewById(R.id.main_layout);
		//layout.setBackgroundColor(Color.BLACK);
		
	}
	
	/** Called when the user clicks the Send button */
	/*public void sendNewButtonMessage(View view) {
	  // Do something in response to button

		Intent intent = new Intent(this, GenerateMusicActivity.class);

		intent.putExtra("key_name", "A#");
		//Intent intent = new Intent(this, NewMusicKeyActivity.class);
		
    startActivity(intent);

    //startActivityForResult(intent, 1);

	}
	
	 @Override
	 protected void onActivityResult(int requestCode, int resultCode, Intent data) {
	  super.onActivityResult(requestCode, resultCode, data);
	  if(resultCode==RESULT_OK && requestCode==1){
	  
	   String msg = data.getStringExtra("result");
	   System.out.println("I got "+msg);

		 Intent intent = new Intent(this, GenerateMusicActivity.class);
		 intent.putExtra("key_name", msg);
			
	   startActivity(intent);
	   
	  }
	  else{
		   System.out.println("I got nothing");}
	 }
	*/
	
	/** Called when the user clicks the Send button */
	/*public void sendLoadButtonMessage(View view) {
	  // Do something in response to button

		//Intent intent = new Intent(this, TabReportActivity.class);

		Scale_Manager major_manager = Major_Scale_Manager.getRandomScale();
	  Scale_Guitar g = new Scale_Guitar(major_manager);
	  
	  Guitar_Tab_Generator gen = new Guitar_Tab_Generator(g, 4,4);
	  
	  gen.generateRandomTabReport();

	  intent.putExtra(TAB_REPORT_MESSAGE, gen.toString());

		intent.putExtra(TAB_REPORT_MESSAGE, "test");
		
    //startActivity(intent);
    
	}*/
	
/*	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
*/
}
