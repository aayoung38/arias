package com.ariasproj.platform.android;

import java.util.ArrayList;
//import java.util.HashMap;
//import java.util.List;

import com.ariasproj.common.types.note.NoteLetter;
import android.app.Activity;
//import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class NewMusicKeyActivity extends Activity {


  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    final Intent returnIntent = getIntent();
    setContentView(R.layout.activity_new_music_key);
   
    final ListView listview = (ListView) findViewById(R.id.music_keys);
    
    final ArrayList<String> list = new ArrayList<String>();
    NoteLetter n = NoteLetter.getNoteLetter(false);
    
    for (int i = 0; i < NoteLetter.getNumberNotes(); ++i) {
      list.add(n.getNote(i));
    }

    final ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,
        android.R.layout.simple_list_item_1, list);
    listview.setAdapter(adapter);
 
		/*listView.setOnItemClickListener(new OnItemClickListener() {
			public void onItemClick(AdapterView<?> parent, View view,
					int position, long id) {
			    // When clicked, show a toast with the TextView text
			    Toast.makeText(getApplicationContext(),
				((TextView) view).getText(), Toast.LENGTH_SHORT).show();
			}
		});*/
    
		listview.setOnItemClickListener(new AdapterView.OnItemClickListener() {

      @Override
      public void onItemClick(AdapterView<?> parent, final View view,
          int position, long id) { 
      	  System.out.println("putting...."+parent.getItemAtPosition(position));
      	  returnIntent.putExtra("result", (String)parent.getItemAtPosition(position));

          setResult(RESULT_OK,returnIntent); 
          
          finish();
         };
      

    });
 
	}

 /* private class StableArrayAdapter extends ArrayAdapter<String> {

    HashMap<String, Integer> mIdMap = new HashMap<String, Integer>();

    public StableArrayAdapter(Context context, int textViewResourceId,
        List<String> objects) {
      super(context, textViewResourceId, objects);
      for (int i = 0; i < objects.size(); ++i) {
        mIdMap.put(objects.get(i), i);
      }
    }

    @Override
    public long getItemId(int position) {
      String item = getItem(position);
      return mIdMap.get(item);
    }

    @Override
    public boolean hasStableIds() {
      return true;
    }

  } */

}