import { useEffect, useState } from "react";
import { getWeather, getCitySuggestions } from "./api/weather";
import WeatherCard from "./components/WeatherCard";
import SearchBar from "./components/SearchBar";

function App() {
  const [suggestions, setSuggestions] = useState<string[]>([]);
  const [city, setCity] = useState("");
  const [weather, setWeather] = useState<Weather | null>(null);

  const [loading, setLoading] = useState(false);
  const [error, setError] = useState("");

  async function searchWeather(searchCity = city) {
    const cleanCity = searchCity.split(",")[0].trim();

    if (!cleanCity) return;

    try {
      setLoading(true);
      setError("");

      const data = await getWeather(cleanCity);

      setWeather(data);
      setCity(cleanCity);
      setSuggestions([]);
    } catch (err) {
      setError("Could not find weather");
      console.error(err);
    } finally {
      setLoading(false);
    }
  }
  useEffect(() => {
    async function fetchSuggestions() {
      if (city.trim().length < 2) {
        setSuggestions([]);
        return;
      }

      try {
        const results = await getCitySuggestions(city);

        setSuggestions(results);
      } catch (err) {
        console.error(err);
        setSuggestions([]);
      }
    }

    fetchSuggestions();
  }, [city]);

  function selectCity(selectedCity: string) {
    const cityName = selectedCity.split(",")[0];

    setCity(cityName);
    searchWeather(cityName);
  }

  return (
    <div
      className="
        min-h-screen
        bg-gradient-to-br
        from-zinc-900
        via-slate-800
        to-zinc-700
        flex
        flex-col
        items-center
        justify-center
        gap-6
      "
    >
      <h1 className="text-5xl font-bold text-white">IntWeather</h1>

      <SearchBar
        city={city}
        setCity={setCity}
        onSearch={searchWeather}
        suggestions={suggestions}
        onSelectSuggestion={selectCity}
      />

      {loading && <p className="text-white">Loading weather...</p>}

      {error && <p className="text-white">{error}</p>}

      {weather && <WeatherCard weather={weather} />}
    </div>
  );
}

export default App;
