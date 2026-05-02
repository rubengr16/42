from datetime import datetime

current_date = datetime.now()
current_date_secs = current_date.timestamp()
print(f"Seconds since January 1, 1970: {current_date_secs:,.4f} or {current_date_secs:.2e} in scientific notation")
print(current_date.strftime("%b %d %Y"))
