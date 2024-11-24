First you need to compile the code using
 gcc api.c json.c main.c -o run -lcurl -lcjson

# here output_to_files.sh is the shell script file which is storing weather information in output file.
# change script.sh to output_to-files.sh


for automation in Linux,
you need to do this

chmod +x /path/to/your/script.sh    #Make sure the script is executable by running the following command

crontab -e                                   #Open the cron table for your user


0 10 * * * /path/to/your/script.sh  # 0 10 — 10:00 AM (minute 0, hour 10)
                                             # * * * — Every day of the month, every month, every day of the week.
                                             #/path/to/your/script.sh — Full path to your shell script.



crontab -l                                   #To verify that your cron job is scheduled, run
