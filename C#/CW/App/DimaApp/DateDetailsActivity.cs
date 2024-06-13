using Android.App;
using Android.Content;
using Android.OS;
using Android.Widget;
using System;

namespace DimaApp
{
    [Activity(Label = "Date Details")]
    public class DateDetailsActivity : Activity
    {
        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);
            SetContentView(Resource.Layout.activity_date_details);

            string selectedDate = Intent.GetStringExtra("SelectedDate") ?? "No date selected";

            TextView selectedDateTextView = FindViewById<TextView>(Resource.Id.selectedDateTextView);
            selectedDateTextView.Text = "Selected Date: " + selectedDate;

            ISharedPreferences sharedPreferences = GetSharedPreferences(selectedDate, FileCreationMode.Private);
            LinearLayout hoursContainer = FindViewById<LinearLayout>(Resource.Id.hoursContainer);

            EditText dayTypeEditText = FindViewById<EditText>(Resource.Id.dayTypeEditText);
            string dayTypeKey = "DayType";
            string savedDayType = sharedPreferences.GetString(dayTypeKey, "");
            dayTypeEditText.Text = savedDayType;

            Button saveDayTypeButton = FindViewById<Button>(Resource.Id.saveDayTypeButton);
            saveDayTypeButton.Click += (sender, e) =>
            {
                string dayType = dayTypeEditText.Text;

                ISharedPreferencesEditor editor = sharedPreferences.Edit();
                editor.PutString(dayTypeKey, dayType);
                editor.Apply();

                Toast.MakeText(this, "Day type saved", ToastLength.Short).Show();
            };


            for (int i = 0; i < 24; i++)
            {
                string hourKey = i.ToString();

                TextView textView = new TextView(this);
                textView.Text = i.ToString() + ":00";

                EditText taskEditText = new EditText(this);
                taskEditText.Hint = "Enter a task for this hour";

                string savedTask = sharedPreferences.GetString(hourKey, "");
                taskEditText.Text = savedTask;

                Button saveButton = new Button(this);
                saveButton.Text = "Save Task";

                int hour = i;
                saveButton.Click += (sender, e) =>
                {
                    string task = taskEditText.Text;

                    ISharedPreferencesEditor editor = sharedPreferences.Edit();
                    editor.PutString(hourKey, task);
                    editor.Apply();

                    Toast.MakeText(this, "Task saved for hour " + hour, ToastLength.Short).Show();
                };

                hoursContainer.AddView(textView);
                hoursContainer.AddView(taskEditText);
                hoursContainer.AddView(saveButton);
            }
        }
    }
}
