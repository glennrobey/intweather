import { useState } from "react";
import { getWeather, type Weather } from "./api/weather";
import WeatherCard from "./components/WeatherCard";

function App() {
  const [city, setCity] = useState("");
  const [weather, setWeather] = useState<Weather | null>(null);

  const [loading, setLoading] = useState(false);
  const [error, setError] = useState("");

  async function searchWeather() {
    try {
      setLoading(true);
      setError("");

      const data = await getWeather(city);

      setWeather(data);
    } catch (err) {
      setError("Could not find weather");
      console.error(err);
    } finally {
      setLoading(false);
    }
  }

  return (
    <div className="min-h-screen bg-blue-500 flex items-center justify-center">
      <h1 className="text-5xl font-bold text-white">IntWeather</h1>

      <input
        value={city}
        onChange={(e) => setCity(e.target.value)}
        placeholder="Enter city"
      />

      <button onClick={searchWeather}>Search</button>

      {loading && <p>Loading weather...</p>}

      {error && <p>{error}</p>}

      {weather && <WeatherCard weather={weather} />}
    </div>
  );
}

export default App;
