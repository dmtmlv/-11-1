using Android.App;
using Android.Content;
using Android.OS;
using Android.Widget;
using AndroidX.AppCompat.App;
using System;

namespace DimaApp
{
    [Activity(Label = "Simple Calendar", MainLauncher = true)]
    public class MainActivity : AppCompatActivity
    {
        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);
            SetContentView(Resource.Layout.activity_main);

            CalendarView calendarView = FindViewById<CalendarView>(Resource.Id.calendarView);
            TextView selectedDateTextView = FindViewById<TextView>(Resource.Id.selectedDateTextView);
            LinearLayout tasksLinearLayout = FindViewById<LinearLayout>(Resource.Id.tasksLinearLayout);

            var today = DateTime.Today.Date;

            // Загружаем сохраненный Day Type для текущей даты
            ISharedPreferences todaySharedPreferences = GetSharedPreferences(today.ToString("dd/MM/yyyy"), FileCreationMode.Private);
            string savedDayType = todaySharedPreferences.GetString("DayType", "");
            selectedDateTextView.Text = savedDayType;

            LoadTasksForDate(today, tasksLinearLayout);

            calendarView.DateChange += (sender, e) =>
            {
                var selectedDate = new DateTime(e.Year, e.Month + 1, e.DayOfMonth).ToString("dd/MM/yyyy");
                Intent intent = new Intent(this, typeof(DateDetailsActivity));
                intent.PutExtra("SelectedDate", selectedDate);
                StartActivity(intent);

                DateTime date = new DateTime(e.Year, e.Month + 1, e.DayOfMonth);
                LoadTasksForDate(date, tasksLinearLayout);

                // Загружаем сохраненный Day Type для выбранной даты
                ISharedPreferences selectedDateSharedPreferences = GetSharedPreferences(selectedDate, FileCreationMode.Private);
                string selectedDayType = selectedDateSharedPreferences.GetString("DayType", "");
                selectedDateTextView.Text = selectedDayType;
            };
        }

        private void LoadTasksForDate(DateTime date, LinearLayout tasksLinearLayout)
        {
            string selectedDate = date.ToString("dd/MM/yyyy");
            ISharedPreferences sharedPreferences = GetSharedPreferences(selectedDate, FileCreationMode.Private);

            tasksLinearLayout.RemoveAllViews();

            for (int i = 0; i < 24; i++)
            {
                string hourKey = i.ToString();
                string savedTask = sharedPreferences.GetString(hourKey, "");

                if (!string.IsNullOrEmpty(savedTask))
                {
                    CheckBox taskCheckBox = new CheckBox(this);
                    taskCheckBox.Text = i.ToString("00") + ":00 - " + savedTask;
                    taskCheckBox.Checked = sharedPreferences.GetBoolean(hourKey + "_checked", false);

                    taskCheckBox.CheckedChange += (s, ev) =>
                    {
                        ISharedPreferencesEditor editor = sharedPreferences.Edit();
                        editor.PutBoolean(hourKey + "_checked", taskCheckBox.Checked);
                        editor.Apply();
                    };

                    tasksLinearLayout.AddView(taskCheckBox);
                }
            }
        }
    }
}