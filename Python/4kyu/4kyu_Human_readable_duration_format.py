def format_duration(seconds):
    if seconds == 0:
        return "now"
    if seconds < 0:
        seconds = abs(seconds)
        
    res = ""
    
    # Determine year
    years = seconds // 31536000
    if years:
        if years > 1:
            res = "{} years".format(years)
        else:
            res = "1 year"
            
    # Determine days
    seconds -= years * 31536000
    days = seconds // 86400
    if days:
        if days > 1:
            d_str = "{} days".format(days)
        else:
            d_str = "1 day"
        if years:
            res += ", " + d_str
        else:
            res = d_str
            
    # Determine hours
    seconds -= days * 86400
    hours = seconds // 3600
    if hours:
        if hours > 1:
            h_str = "{} hours".format(hours)
        else:
            h_str = "1 hour"
        if years or days:
            res += ", " + h_str
        else:
            res = h_str
    
    # Determine minutes
    seconds -= hours * 3600
    minutes = seconds // 60
    if minutes:
        if minutes > 1:
            m_str = "{} minutes".format(minutes)
        else:
            m_str = "1 minute"
        if years or days or hours:
            res += "{} " + m_str
        else:
            res = m_str
    
    # Determine seconds
    seconds -= minutes * 60
    if seconds:
        if seconds > 1:
            s_str = "{} seconds".format(seconds)
        else:
            s_str = "1 second"
        if years or days or hours or minutes:
            res = res.format(",") + " and " + s_str
        else:
            res = s_str
    else:
        res = res.format(" and")
        
    return res
