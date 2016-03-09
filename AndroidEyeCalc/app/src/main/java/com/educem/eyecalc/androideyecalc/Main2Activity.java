package com.educem.eyecalc.androideyecalc;

import android.content.Intent;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.provider.MediaStore;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

public class Main2Activity extends AppCompatActivity {

    Button tkfoto;
    ImageView takenfoto;
    private static final int CAM_REQUEST=1313;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        tkfoto = (Button) findViewById(R.id.btTakePhoto);
        takenfoto = (ImageView) findViewById(R.id.imgTaken);

        tkfoto.setOnClickListener(new takenfotoClicker());
}
@Override
protected void onActivityResult(int requestCode, int resultCode, Intent Data){
    super.onActivityResult(requestCode, resultCode, Data);

    if(requestCode == CAM_REQUEST){
        Bitmap bmp = (Bitmap) Data.getExtras().get("data");
        takenfoto.setImageBitmap(bmp);
    }
}

class takenfotoClicker implements Button.OnClickListener
{
    @Override
    public void onClick(View v) {
        Intent  cameraIntent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
        startActivityForResult(cameraIntent,CAM_REQUEST);
    }
}