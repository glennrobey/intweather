import type { Weather } from "../api/weather";

interface Props {
  weather: Weather;
}

function WeatherCard({ weather }: Props) {
  return (
    <div>
      <h2>{weather.city}</h2>

      <p>{weather.condition}</p>

      <p>
        Temperature:
        {weather.temperatureF}°F
      </p>

      <p>
        Feels like:
        {weather.feelsLikeF}°F
      </p>

      <p>
        Humidity:
        {weather.humidity}%
      </p>

      <p>
        Wind:
        {weather.windSpeedMph} mph
      </p>
    </div>
  );
}

export default WeatherCard;
