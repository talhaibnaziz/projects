package com.cse.mist.shurokkhav5;



import android.content.Context;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;


/**
 * A simple {@link Fragment} subclass.
 */
public class ProfileFragment extends Fragment {


    public ProfileFragment() {
        // Required empty public constructor
    }

    @Override //called when fragment is called
    public void onAttach(Context context) {
        super.onAttach(context);
    }

    @Override //
    public void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override //layout inflate kore :|
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        return inflater.inflate(R.layout.fragment_profile, container, false);
    }

    @Override //instance dibe of activities, eta on create of activity, orientation change holeo lage
    public void onActivityCreated(@Nullable Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);
    }

    @Override //fragment destroy korte
    public void onDestroy() {
        super.onDestroy();
    }

    @Override //completely fragment destroy kore apparently
    public void onDetach() {
        super.onDetach();
    }
}
